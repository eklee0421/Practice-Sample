#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_routine(int sick, char *buf);
void write_routine(int sock, char *buf);


int main(int argc, char *argv[]) {

	int sock;		//클라이언트 측의 소켓
	pid_t pid;
	char buf[BUF_SIZE];
	struct sockaddr_in serv_adr;	//서버 목적지의 정보를 저장하는 구조체

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);	//TCP 소켓 생성 

	//주소 정보를 담는 구조체 초기화
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error!");

	pid = fork();
	if (pid == 0)
		write_routine(sock, buf);
	else
		read_routine(sock, buf);
	close(sock);	
	
	return 0;
}

void read_routine(int sock, char *buf) {
	while (1) {
		int str_len = read(sock, buf, BUF_SIZE); 
		if (str_len == 0)	//입력 받은 것이 없으면 종료
			return;
		
		buf[str_len] = 0;
		printf("Message from server: %s", buf);
	}
}

void write_routine(int sock, char *buf) {
	while (1) {
		fgets(buf, BUF_SIZE, stdin);
		if (!strcmp(buf, "q\n") || !strcmp(buf, "Q\n")) {
			shutdown(sock, SHUT_WR);
			return;
		}
		write(sock, buf, strlen(buf));
	}
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}