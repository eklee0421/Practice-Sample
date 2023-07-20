#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[]) {

	//���� ���� ��ũ���� ���� ����
	int serv_sock, clnt_sock;	//��������-���� ��û�� �޴� ����, Ŭ���̾�Ʈ����-data �ۼ����� ���� ����
	char message[BUF_SIZE];	//���� �� ���̴��� ��� char�� �迭
	int str_len, i;	//str_len: raed �Լ����� �� ���ڸ� �о�Դ��� �����ϴ� ����, i: �ݺ������� ���� ����

	struct sockaddr_in serv_adr;	//�������Ͽ� �ּ����� �Ҵ� �� �� ���̴� ����ü
	struct sockaddr_in clnt_adr;	//accept�Լ� ���ڷ� �� ����ü - ���� ��û�� �� Ŭ���̾�Ʈ�� �ּ������� �Բ� ����
	socklen_t clnt_adr_sz;	//clnt_adr�� ũ�⸦ ����ִ� ����

	if (argc != 2) {	//���� ����� ���� ����ó�� ��� �ȳ�
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	/*�߿��� �κ�!*/
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);	//�����Լ��� ���ؼ� ���������� ���� tcp���� ����, ���� ��ũ���Ͱ� ����
	if (serv_sock == -1)
		error_handling("socket() error");

	//�ּ� ������ ��� ����ü �ʱ�ȭ
	memset(&serv_adr, 0, sizeof(serv_adr));	
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);	//�ڽ��� ip�� �ڵ����� �־��ش�
	serv_adr.sin_port = htons(atoi(argv[1]));	//port ��ȣ�� ���α׷��Ӱ� �Է��� ���ڿ� ���� �ٽ� int������ �ٲٰ� network byte ������ �ٲ㼭 ����
	
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)	//�ּ� ���� �Ҵ�
		error_handling("bind() error");
		
	if (listen(serv_sock, 5) == -1)	//���� ������ ���ڷ� ����, ���� ��û ��� ť�� ũ��� 5
		error_handling("listen() error");

	clnt_adr_sz = sizeof(clnt_adr); //client address�� ũ�⸦ �� ������ ����

	for (i = 0; i < 5; i++) {
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);	//������ ������ �ۼ����� ����ϴ� ����
		if (clnt_sock == -1)
			error_handling("accept() error");
		else
			printf("Connected client %d \n", i + 1);

		while ((str_len = read(clnt_sock, message, BUF_SIZE)) != 0) //clnt_sock�� �ִ� data�� �о�ͼ� �޽��� �迭�� ����
			write(clnt_sock, message, str_len);	//���� ���Դٸ� ���� ��ŭ �ٽ� �����ش�!

		close(clnt_sock);	//Ŭ���̾�Ʈ ���ϸ� �ݴ´�
	}

	close(serv_sock); //��� ó���� ������ �ݺ��� �������ͼ� �������ϵ� �ݴ´�
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}