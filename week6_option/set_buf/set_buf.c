//소켓의 입출력 버퍼 크기 변경

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
	int sock;
	int snd_buf = 1024 * 3, rcv_buf = 1024 * 3;	
	/*이렇게 변경해도, 입출력 버퍼의 크기는 주의 깊게 다뤄져야 하므로
	운영체제가 적절하게 바꾸지만, 시그윈에서는 그대로 출력된다
	우분투와 같은 다른 리눅스 운영체제에서는 운영체제가 변경한 값이 출력된다
	*/
	int state;
	socklen_t len;
	
	sock = socket(PF_INET, SOCK_STREAM, 0);
	
	state = setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void*)&snd_buf, sizeof(rcv_buf));
	if (state)
		error_handling("setsockopt() error");

	len = sizeof(rcv_buf);
	state = setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void*)&rcv_buf, sizeof(snd_buf));
	if (state)
		error_handling("setsockopt() error");
	
	len = sizeof(snd_buf);
	state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void*)&snd_buf, &len);
	if (state)
		error_handling("getsockopt() error");

	len = sizeof(rcv_buf);
	state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void*)&rcv_buf, &len);
	if (state)
		error_handling("getsockopt() error");

	printf("Input buffer size: %d \n", rcv_buf);	
	printf("Output buffer size: %d \n", snd_buf);
	
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}