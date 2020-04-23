#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 50
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int serv_sd, clnt_sd;
	FILE * fp;	//파일 입출력에 사용될 포인터 변수
	char buf[BUF_SIZE];	//내용이 담길 버퍼
	int read_cnt;	//data의 크기를 count하는 변수

	struct sockaddr_in serv_adr, clnt_adr;	//서버 주소와 클라이언트 주소가 선언될 구조체
	socklen_t clnt_adr_sz;

	if (argc != 2) {	
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	fp = fopen("file_server.c", "rb");	//rb-2진형식의 읽기모드로 file_server.c라는 파일 열고 있음
	serv_sd = socket(PF_INET, SOCK_STREAM, 0);	//tcp 소켓 생성

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));	//서버 주소에 소켓 할당
	listen(serv_sd, 5);	//listening 소켓으로 만들어 주고 있다

	clnt_adr_sz = sizeof(clnt_adr);
	clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);	//data 송수신 담당용 소켓 생성
	
	while (1) {
		read_cnt = fread((void*)buf, 1, BUF_SIZE, fp);	//fread함수를 통해서 fp가 가리키는 파일 스트림에서 버퍼에 그 값들을 읽어오고 있다
		if (read_cnt < BUF_SIZE) {	//마지막 버퍼 사이즈만큼 읽어오지 못한 경우에는 읽어온만큼만 전송을 하고 while문 빠져나가라는 의미
			write(clnt_sd, buf, read_cnt);	//갯수만큼 읽어와서 버퍼에 저장
			break;
		}
		write(clnt_sd, buf, BUF_SIZE);	//읽어온 data의 크기만큼 client로 다시 전송
	}

	shutdown(clnt_sd, SHUT_WR); //half-close 출력스트림만 닫아준다 -> EOF가 client에 간다
	read(clnt_sd, buf, BUF_SIZE);
	printf("Message from client: %s \n", buf);

	fclose(fp);
	close(clnt_sd); close(serv_sd);

	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}