#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4		//피연산자를 4byte로 입력 받을 예정
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int sock;		//클라이언트 측의 소켓
	char opmsg[BUF_SIZE];	//캐릭터형 배열
	int result, opnd_cnt, i;	//연산 결과 저장하는 변수, 피연산자에 사용하는 변수, 반복문에 사용되는 변수
	struct sockaddr_in serv_adr;	//서버 목적지의 정보를 저장하는 구조체

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);	//TCP 소켓 생성 
	if (sock == -1)
		error_handling("socket() error");

	//주소 정보를 담는 구조체 초기화
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error!");
	else
		puts("connected.......");
	
	fputs("Operand count: ", stdout);	//피연산자 수 입력 안내
	scanf("%d", &opnd_cnt);
	opmsg[0] = (char)opnd_cnt;	//캐릭터 형변환

	for (i = 0; i < opnd_cnt; i++) {	//피연산자 입력
		printf("Operand %d: ", i + 1);
		scanf("%d", (int*)&opmsg[i * OPSZ + 1]);
		//printf("%d", (int*)&opmsg[i * OPSZ + 1]);
	}
	fgetc(stdin);	//표준 입력 버퍼 비워주기 (개행 문자, NULL 문자 비우기)
	fputs("Operator: ", stdout);
	scanf("%c", &opmsg[opnd_cnt*OPSZ + 1]);	//연산자 입력 받기(1byte로 입력 받음)
	write(sock, opmsg, opnd_cnt*OPSZ + 2);
	read(sock, &result, RLT_SIZE);	//4byte만 받을 예정이기 때문에 오류가 날 가능성은 적다

	printf("Operation result: %d \n", result);

	close(sock);
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}