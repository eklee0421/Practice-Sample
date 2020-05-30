#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_childproc(int sig);	//좀비프로세스가 되지 않도록 자식 프로세스 종료시 호출되는 함수

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//소켓 파일 디스크립터를 담는 변수들
	struct sockaddr_in serv_adr, clnt_adr;	//주소를 담는 구조체들

	pid_t pid;	//프로세스 id를 담는 변수 pid
	struct sigaction act;	//시그널 발생시 호출된 함수를 담는 구조체
	socklen_t adr_sz;
	int str_len, state;
	char buf[BUF_SIZE];

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
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

	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	while (1) {
		adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
		if (clnt_sock == -1)
			continue;
		else
			puts("new client connected...");
		pid = fork();
		//자식 프로세스 실행 영역
		if (pid == 0) {
			close(serv_sock);
			while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
				write(clnt_sock, buf, str_len);

			close(clnt_sock);
			puts("client disconnected...");	
			return 0;	//자식은 자기 자신 종료 - 시그널 발생해서 부모는 시그널을 받게 된다
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);
	
	return 0;
}

void read_childproc(int sig) {

	int status;
	pid_t pid = waitpid(-1, &status, WNOHANG);
	printf("Remove proc id: %d \n", pid);	//임의의 자식을 대상으로 블로킹 상태에 놓이지 않도록 한다
	
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}