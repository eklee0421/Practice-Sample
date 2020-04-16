#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int serv_sock;	//파일 디스크립터로 관리하기 때문에 그 파일 디스크립터를 저장할 변수
	char message[BUF_SIZE];	//data를 수신할 버퍼
	struct sockaddr_in my_adr, your_adr;
	socklen_t adr_sz;
	int str_len, i;	//수신한 data의 길이를 저장할 변수

	if (argc != 2) {	
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_DGRAM, 0);	//SOCK_DGRAM을 사용하면 비연결지향형인 UDP 소켓 생성
	if (serv_sock == -1)
		error_handling("UDP socket creation error");

	//서버 주소정보를 담을 구조체 초기화
	memset(&my_adr, 0, sizeof(my_adr));
	my_adr.sin_family = AF_INET;
	my_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_adr.sin_port = htons(atoi(argv[1]));
	
	if (bind(serv_sock, (struct sockaddr*)&my_adr, sizeof(my_adr)) == -1)	//목적지가 되어줘야 하는 소켓이기 때문에 주소를 할당해주어야 한다
		error_handling("bind() error");
		
	for (i = 0; i < 3; i++) {

		sleep(5);	//delay 5 sec.
		adr_sz = sizeof(your_adr);	//data 발신지의 정보를 담을 변수
		str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&your_adr, &adr_sz);
		printf("Mesaage %d: %s \n", i + 1, message);
	}

	close(serv_sock); 
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}