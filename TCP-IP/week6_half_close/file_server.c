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
	FILE * fp;	//���� ����¿� ���� ������ ����
	char buf[BUF_SIZE];	//������ ��� ����
	int read_cnt;	//data�� ũ�⸦ count�ϴ� ����

	struct sockaddr_in serv_adr, clnt_adr;	//���� �ּҿ� Ŭ���̾�Ʈ �ּҰ� ����� ����ü
	socklen_t clnt_adr_sz;

	if (argc != 2) {	
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	fp = fopen("file_server.c", "rb");	//rb-2�������� �б���� file_server.c��� ���� ���� ����
	serv_sd = socket(PF_INET, SOCK_STREAM, 0);	//tcp ���� ����

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));	//���� �ּҿ� ���� �Ҵ�
	listen(serv_sd, 5);	//listening �������� ����� �ְ� �ִ�

	clnt_adr_sz = sizeof(clnt_adr);
	clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);	//data �ۼ��� ���� ���� ����
	
	while (1) {
		read_cnt = fread((void*)buf, 1, BUF_SIZE, fp);	//fread�Լ��� ���ؼ� fp�� ����Ű�� ���� ��Ʈ������ ���ۿ� �� ������ �о���� �ִ�
		if (read_cnt < BUF_SIZE) {	//������ ���� �����ŭ �о���� ���� ��쿡�� �о�¸�ŭ�� ������ �ϰ� while�� ����������� �ǹ�
			write(clnt_sd, buf, read_cnt);	//������ŭ �о�ͼ� ���ۿ� ����
			break;
		}
		write(clnt_sd, buf, BUF_SIZE);	//�о�� data�� ũ�⸸ŭ client�� �ٽ� ����
	}

	shutdown(clnt_sd, SHUT_WR); //half-close ��½�Ʈ���� �ݾ��ش� -> EOF�� client�� ����
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