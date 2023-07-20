#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 50
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int sd;
	FILE *fp;

	char buf[BUF_SIZE];
	int read_cnt;
	struct sockaddr_in serv_adr;

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	fp = fopen("receive.dat", "wb");	//"receive.dat"��� ������ wb-���̳ʸ� ���� �������� ����
	sd = socket(PF_INET, SOCK_STREAM, 0);	//tcp ���� ���� 
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	connect(sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));	//������ ���� ��û

	while ((read_cnt == read(sd, buf, BUF_SIZE)) != 0)	//����ؼ� ���� ���� �޴� ����.. -eof ���� Ż��
		fwrite((void*)buf, 1, read_cnt, fp);

	puts("Receive file data");
	write(sd, "Thank you", 10);
	fclose(fp);
	close(sd);
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}