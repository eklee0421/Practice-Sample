#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/select.h>

#define BUF_SIZE 100
void error_handling(char *message);
void read_childproc(int sig);	//좀비프로세스가 되지 않도록 자식 프로세스 종료시 호출되는 함수

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//소켓 파일 디스크립터를 담는 변수들
	struct sockaddr_in serv_adr;	//주소를 담는 구조체들
	struct sockaddr_in clnt_adr;
	int fds[2];	//파이프의 파일 디스크립터가 저장 될 배열
	
	pid_t pid;	//프로세스 id를 담는 변수 pid
	struct sigaction act;	//시그널 발생시 호출된 함수를 담는 구조체
	socklen_t adr_sz;
	int str_len, state;
	char buf[BUF_SIZE];


	if (argc != 2) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler = read_childproc;	//시그널 등록을 위해 sigaction 구조체에 read_childproc의 주소값 저장
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0);	//시그널 등록

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);	//소켓 생성
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	pipe(fds);	//부모프로세스가 파이프 생성
	pid = fork();	//자식프로세스 생성	- 파일 저장하는 역할
	if (pid == 0) {
		FILE * fp = fopen("echomsg.txt", "wt");
		char msgbuf[BUF_SIZE];
		int i, len;

		for (i = 0; i < 10; i++) {
			len = read(fds[0], msgbuf, BUF_SIZE);	//파이프의 출구를 통해서 read 함수 읽어오고 msgbuf에 저장
			fwrite((void*)msgbuf, 1, len, fp);
		}
		fclose(fp);
		return 0;
	}

	while (1) {
		adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
		if (clnt_sock == -1) continue;
		else puts("new client connected...");

		pid = fork();	//새로운 자식 프로세스 생성 - data 송수신을 담당하는 프로세스
		if (pid == 0) {
			close(serv_sock);	//연결 요청을 받는 서버 소켓은 필요 없으니 닫아준다
			while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0) {
				write(clnt_sock, buf, str_len);
				write(fds[1], buf, str_len);		//입구를 통해서 data 전송 - 이 data가 첫번째 자식 프로세스가 읽게 되는 data
			}
			close(clnt_sock);	//data 전송이 모두 끝나면 클라이언트와 연결된 모든 소켓을 닫고 종료
			puts("clients disconnected...");
			return 0;
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);
	return 0;


}

void read_childproc(int sig) {
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("removed proc id: %d \n", pid);	//임의의 자식을 대상으로 블로킹 상태에 놓이지 않도록 한다
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}