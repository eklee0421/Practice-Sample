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
	int str_len;	//수신한 data의 길이를 저장할 변수
	socklen_t clnt_adr_sz;	//구조체의 크리를 담을 변수

	struct sockaddr_in serv_adr, clnt_adr;	//주소정보를 담을 구조체들

	if (argc != 2) {	
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_DGRAM, 0);	//SOCK_DGRAM을 사용하면 비연결지향형인 UDP 소켓 생성
	if (serv_sock == -1)
		error_handling("UDP socket creation error");

	//서버 주소정보를 담을 구조체 초기화
	memset(&serv_adr, 0, sizeof(serv_adr));	
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);	
	serv_adr.sin_port = htons(atoi(argv[1]));	
	
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)	//목적지가 되어줘야 하는 소켓이기 때문에 주소를 할당해주어야 한다
		error_handling("bind() error");
		
	while (1) {	//echo 작업을 하기 위한 코드들
		clnt_adr_sz = sizeof(clnt_adr);	//clnt 주소 정보를 담는 구조체의 변수 길이 저장
		str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);	//recvfrom 함수를 통해서 clnt로부터 수신한 data를 읽어오기
		sendto(serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_adr, clnt_adr_sz);	//수신한 data를 그대로 보내주기 위해 sendto 함수 호출
	}

	//while문을 빠져나가기 위한 break문이 없기 때문에 아래 문장은 실행 될 수 없다
	close(serv_sock); 
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}