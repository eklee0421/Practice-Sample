#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 100
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//서버소켓-연결 요청을 받는 소켓, 클라이언트소켓-data 송수신을 위한 소켓
	char buf[BUF_SIZE];	//전송 할 데이더가 담긴 char형 배열
	int str_len, i;	//str_len: raed 함수에서 몇 글자를 읽어왔는지 저장하는 변수, i: 반복문에서 쓰일 변수(파일 디스크립터처럼 이용도 됨)
	int fd_max, fd_num;	//fd_max: 현재 가장 큰 파일 디스크립터 의미, fd_num: select 함수의 반환값 저장
	struct timeval timeout;
	fd_set reads, cpy_reads;

	struct sockaddr_in serv_adr;	//서버소켓에 주소정보 할당 할 때 쓰이는 구조체
	struct sockaddr_in clnt_adr;	//accept함수 인자로 들어갈 구조체 - 연결 요청을 한 클라이언트의 주소정보를 함께 저장
	socklen_t adr_sz;	//clnt_adr의 크기를 담아주는 변수

	if (argc != 2) {	//실행 방법에 대한 오류처리 방법 안내
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));	
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);	
	serv_adr.sin_port = htons(atoi(argv[1]));	
	
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)	
		error_handling("bind() error");
		
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	FD_ZERO(&reads);
	FD_SET(serv_sock, &reads);	//처음에는 관찰 대상에 serv_sock만 넣어주게 된다
	//표준 입력, 표준 출력, 표준 에러 및 서버 소켓이 파일 디스크립터 사용중 - 순서대로 0 1 2 3 사용
	fd_max = serv_sock;	//fd_max == 3

	while (1) {
		cpy_reads = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;

		if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout)) == -1)
			break;	//실패 했다면 바로 break해서 끝나게 된다
		
		if (fd_num == 0) 
			continue;	//0이라면 while문의 처음으로 돌아가서 다시...
		

		for (i = 0; i < fd_max + 1; i++) {
			if (FD_ISSET(i, &cpy_reads)) {	//해당 파일 디스크립터에 변화가 있었는지 확인
				if (i == serv_sock) {	//connection request! - 만약 서버 소켓에 연결 요청이 들어왔다면 서버 소켓에 data 입력! 나머지들은 아직 0
					adr_sz = sizeof(clnt_adr);
					clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);	//서버 소켓에서는 accept함수를 통해서 연결 요청수락하고 새로운 소켓(파일 디스크립터로)
					
					/*중요한 부분!*/
					FD_SET(clnt_sock, &reads);	//새로 만든 소켓(=data 수신할 소켓)을 관찰대상으로!
					
					if (fd_max < clnt_sock)	//clnt_sock==4가 된다 - 처음이라면 updata 해줄 필요
						fd_max = clnt_sock;
					printf("connected client: %d \n", clnt_sock);	//해당 클라이언트와 연결되었다는 안내문을 출력
				}
				else {	//read message! - 변경된 파일 디스크립터가 있었고, 그것이 서버 소켓이 아니라면!
					str_len = read(i, buf, BUF_SIZE);
					if (str_len == 0) {	//close request! - 읽어온 data가 없다면 클라이언트에서 data 송수신 끝낸 것
						FD_CLR(i, &reads);	//관찰 대상에서 제거
						close(i);	//소켓 닫아주기
						printf("close client: %d \n", i);	//소켓 종료 안내문
					}
					else {
						write(i, buf, str_len);	//echo! - 읽어온 data가 있다면 
					}
				}
			}
		}
	}
	close(serv_sock);
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}