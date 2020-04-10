#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4
void error_handling(char *message);
int calculate(int opnum, int opnds[], char op);	//int�� ���� ��ȯ, �ǿ�����, ������

int main(int argc, char *argv[]) {

	//���� ���� ��ũ���� ���� ����
	int serv_sock, clnt_sock;	//��������-���� ��û�� �޴� ����, Ŭ���̾�Ʈ����-data �ۼ����� ���� ����
	char opinfo[BUF_SIZE];	//���� �� ���̴��� ��� char�� �迭
	int result, opnd_cnt, i;
	int recv_cnt, recv_len;

	struct sockaddr_in serv_adr;	//�������Ͽ� �ּ����� �Ҵ� �� �� ���̴� ����ü
	struct sockaddr_in clnt_adr;	//accept�Լ� ���ڷ� �� ����ü - ���� ��û�� �� Ŭ���̾�Ʈ�� �ּ������� �Բ� ����
	socklen_t clnt_adr_sz;	//clnt_adr�� ũ�⸦ ����ִ� ����

	if (argc != 2) {	//���� ����� ���� ����ó�� ��� �ȳ�
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

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
		opnd_cnt = 0;
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		read(clnt_sock, &opnd_cnt, 1);

		recv_len = 0;
		while ((opnd_cnt*OPSZ + 1) > recv_len) {
			recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
			recv_len += recv_cnt;
		}
		result = calculate(opnd_cnt, (int*)opinfo, opinfo[recv_len - 1]);
		write(clnt_sock, (char*)&result, sizeof(result));
		close(clnt_sock);
	}

	close(serv_sock); //��� ó���� ������ �ݺ��� �������ͼ� �������ϵ� �ݴ´�
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int calculate(int opnum, int opnds[], char op) {
	int result = opnds[0];
	int i;

	switch (op) {
	case '+':
		for (i = 1; i < opnum; i++) result += opnds[i];
		break;
	case '-':
		for (i = 1; i < opnum; i++) result -= opnds[i];
		break;
	case '*':
		for (i = 1; i < opnum; i++) result *= opnds[i];
		break;
	}

	return result;
}