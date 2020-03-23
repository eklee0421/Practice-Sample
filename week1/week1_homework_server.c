#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#define BUF_SIZE 9

void error_handling(char *message);	//에러가 날 경우에 호출

int main(int argc, char *argv[])
{
	//파일 디스크립터를 저장하기 위해 사용되는 변수
    int serv_sock;	// 서버 소켓
    int clnt_sock;	// 클라이언트 소켓 => 서버측에서 클라이언트와 데이터 송수신을 하기 위한 소켓
    int fd;
    char buf[BUF_SIZE];

    struct sockaddr_in serv_addr;	//서버 주소 정보 저장
    struct sockaddr_in clnt_addr;	// 클라이언트 주소 정보 저장
    socklen_t clnt_addr_size;

    char message[BUF_SIZE];	// 송신할 데이터

    if(argc!=2){	// 서버 실행 파일 실행 할 때 입력할 포트 번호가 잘못되었을 때 나오는 에러 문구
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock=socket(PF_INET, SOCK_STREAM, 0);	// 소켓을 생성하는 함수
    if(serv_sock ==-1)	// 에러 핸들링
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));	// 서버 주소 정보 저장하는 구조체 초기화
    // 주소 정보 구조체에 정보를 저장하는 과정
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(argv[1]));	//argv[1] => 서버 실행 파일을 실행 할 때 같이 입력했던 9190 포트 번호
									// 이 변수에 9190 포트 번호가 저장되어 있다가 약간의 변화 과정을 거쳐서 주소 정보를 저장하는 구조체에 저장

    //bind 함수는 소켓에 주소 정보를 할당하는 함수 => bind 함수를 통해 서버 주소 구조체에 저장한 정보를 서버소켓에 할당
    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)	// 서버 소켓 파일 디스크립터가 저장되어 있는 서버 소켓 변수, 서버에 주소 정보를 저장하고 있는 서버 address 구조체
	    error_handling;
    
    // listen 이 끝나고 나면 서버 소켓은 연결 요청을 받을 수 있는 상태가 된다
    // 소켓이 도착한 연결 요청을 수락하는 함수
    // 반환 값으로 파일 디스크립터를 주는데 이것이 연결 요청을 한 클라이언트 소켓과 데이터를 송수하는 소켓신
    if(listen(serv_sock, 5)==-1)	
        error_handling("listen() error");

    clnt_addr_size=sizeof(clnt_addr);
    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
   
    if(clnt_sock==-1)
        error_handling("accept() error");
    
    // week1_homework.txt 파일을 읽기전용으로 여는 부분
    fd = open("week1_homework.txt", O_RDONLY);
    if (fd == -1)
	    error_handling("open() error!");
    //printf("file descriptor: %d \n", fd);

    // week1_homework.txt 파일의 내용을 읽어오는 부분
    if (read(fd, buf, sizeof(buf)) == -1)
	    error_handling("read() error!");
   // printf("file data: %s", buf);
    
    // write 함수를 통해서 데이터를 송수신
    write(clnt_sock, buf, sizeof(buf));
    close(fd);
    close(clnt_sock);
    close(serv_sock);
    
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}