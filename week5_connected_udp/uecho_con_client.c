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
	char message[BUF_SIZE];	//송수신에 사용될 버퍼
	int str_len;	//보낼 data의 크기가 담긴 변수
	//socklen_t adr_sz;	//주소정보가 담기는 구조체의 크기 정보

	struct sockaddr_in serv_adr;
	//struct sockaddr_in from_adr;

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_DGRAM, 0);	//UDP 소켓 생성 
	if (sock == -1)
		error_handling("socket() error");

	//주소 정보를 담는 구조체 초기화
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
	
	//하나의 host와 여러번 반복해서 연결해야 할 때 비용 줄일 수 있다
	connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

	while (1) {
		fputs("Insert meaasge(q to quit): ", stdout);
		fgets(message, sizeof(message), stdin);
		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		//sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
		write(sock, message, strlen(message));
		//adr_sz = sizeof(from_adr);
		//str_len = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_adr, &adr_sz);

		str_len = read(sock, message, sizeof(message) - 1);
		message[str_len] = 0;	//문자열이 끝났음을 알려준다
		printf("Message from server: %s", message);
	}
	 
	close(sock);
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}