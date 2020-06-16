#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100	//채팅 버퍼 사이즈
#define MAX_CLNT 256	//최대 클라이언트 수로 사용될 상수

void * handle_clnt(void * arg);	//쓰레드의 메인 함수로 사용
void send_msg(char * msg, int len);	//메시지를 보낼 때 쓰이는 함수
void error_handling(char * msg);	

int clnt_cnt = 0;	//클라이언트 개수 기록
int clnt_socks[MAX_CLNT];	//클라이언트 소켓 모아두고 관리할 배열
pthread_mutex_t mutx;	//뮤텍스 참조할 변수 선언

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//서버와 클라이언트 소켓 
	struct sockaddr_in serv_adr, clnt_adr;	//주소 정보 구조체
	int clnt_adr_sz;
	pthread_t t_id;	//쓰레드 id 담을 변수
	if (argc != 2) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutx, NULL);	//뮤텍스 생성
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
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

		pthread_mutex_lock(&mutx);	//임계영역 시작
		clnt_socks[clnt_cnt++] = clnt_sock;	//새롭게 등록된 클라이언트 소켓 관리
		pthread_mutex_unlock(&mutx);	//임계영역 끝

		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);	//쓰레드 생성
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
	}
	close(serv_sock);
	return 0;
}

void * handle_clnt(void * arg) {	//쓰레드의 메인 함수 역할
	int clnt_sock = *((int*)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];

	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		send_msg(msg, str_len);

	pthread_mutex_lock(&mutx);	//연결 종료된 파일 디스크립터를 정리
	for (i = 0; i < clnt_cnt; i++) {	//remove disconnected client
		if (clnt_sock == clnt_socks[i]) {	//배열 재정리! 빈 클라이언트 자리 채워주기 - 그동안 뮤텍스로 임계영역 보호
			while (i < clnt_cnt - 1) {
				clnt_socks[i] = clnt_socks[i + 1];
				i++;
			}
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}

void send_msg(char * msg, int len) {	//메시지를 보내는 역할
	int i;
	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++)
		write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mutx);
}

void error_handling(char * msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}