/*
in_addr형 구조체 변수에 변환의 결과가 저장
문자열을 네트워크 바이트 순서로 정렬된 정수형 IP주소로 변환
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	char *addr = "127.232.124.79";
	struct sockaddr_in addr_inet;

	if (!inet_aton(addr, &addr_inet.sin_addr))
		error_handling("Conversion error");
	else printf("Network ordered integer addr: %#x \n", addr_inet.sin_addr.s_addr);

     return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}