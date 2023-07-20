#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int sock;		//클라이언트 측의 소켓
	char message[BUF_SIZE];
	int str_len;
	int recv_len;
	int recv_cnt;
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
	
	while (1) {
		fputs("Input messag(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		
		if(!strcmp(message,"q\n") || !strcmp(message, "Q\n"))	//입력된 메시지가 Q(q)라면 데이터 전송 종료
			break;
		
		str_len = write(sock, message, strlen(message));	//보낸 데이터 길이만큼 저장
		
		recv_len = 0;
		while (recv_len < str_len) {	//!=으로 해도 되지만 그럼 recv_len이 더 길 때 빠져나오지 못하고 무한루프에 빠질 가능성 있음
			recv_cnt = read(sock, &message[recv_len], BUF_SIZE - 1);
			if (recv_cnt == -1)
				error_handling("read() errer!");
			recv_len += recv_cnt;	//전체 데이터 길이 받아오기
		}

		message[recv_len] = 0;
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