#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 9

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;	// 소켓
    struct sockaddr_in serv_addr;	// 주소 정보를 저장
    char message[BUF_SIZE];	//수신한 메시지를 담을 캐릭터형 배열
    int str_len;
    int read_len;

    if(argc!=3){
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // 연결 요청 및 데이터 송수신을 하는 소켓
    sock = socket(PF_INET, SOCK_STREAM, 0);	//소켓을 생성하는 함수를 호출하는 부분
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));	//주소 정보를 담을 구조체 초기화
    //서버 address의 구조체에 저장하여 서버로 연결 요청
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);	//argv[1] => 클라이언트 실행파일을 실행 할 때 입력한 127.0.0.1의 ip 주소
    serv_addr.sin_port=htons(atoi(argv[2]));	//argv[2] => 9190 포트 번호

    // connect 연결요청을 하는 함수를 호출하는 부분
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	    error_handling("connect() error!");
    
    int idx = 0;
    //read 함수를 여러번에 걸쳐서 받아오기
    while (read_len=read(sock, &message[idx++], 1)) {
	    if (read_len == -1) {
		    error_handling("read() error!");
		    break;
	    }
		    
	    str_len += read_len;
    }  
   
    printf("Message from server: %s \n", message);	//받은 메시지 출력
    printf("Function read call: %d \n", str_len);
    close(sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}