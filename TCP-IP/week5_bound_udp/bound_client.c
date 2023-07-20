#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int sock;	//파일 디스크립터가 담길 변수
	char msg1[] = "Hi!";
	char msg2[] = "I'm another UDP host!";
	char msg3[] = "Nice to meet you";

	struct sockaddr_in your_adr;	//data를 보낼 목적지 주소 정보가 담길 구조체
	socklen_t your_adr_sz;

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_DGRAM, 0);	//UDP 소켓 생성 
	if (sock == -1)
		error_handling("socket() error");

	//목적지 주소 정보를 담는 구조체 초기화
	memset(&your_adr, 0, sizeof(your_adr));
	your_adr.sin_family = AF_INET;
	your_adr.sin_addr.s_addr = inet_addr(argv[1]);
	your_adr.sin_port = htons(atoi(argv[2]));

	sendto(sock, msg1, strlen(msg1), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg2, strlen(msg2), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg3, strlen(msg3), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
	//sendto 함수는 server보다 먼저 실행된다 

	close(sock);
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}