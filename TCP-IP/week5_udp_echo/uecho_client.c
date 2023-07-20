#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int sock;	//���� ��ũ���Ͱ� ��� ����
	char message[BUF_SIZE];	//�ۼ��ſ� ���� ����
	int str_len;	//���� data�� ũ�Ⱑ ��� ����
	socklen_t adr_sz;	//�ּ������� ���� ����ü�� ũ�� ����

	struct sockaddr_in serv_adr, from_adr;	//�������� �ּ����� �� data�� �߽��� ����

	if (argc != 3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_DGRAM, 0);	//UDP ���� ���� 
	if (sock == -1)
		error_handling("socket() error");

	//�ּ� ������ ��� ����ü �ʱ�ȭ
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	while (1) {
		fputs("Insert meaasge(q to quit): ", stdout);
		fgets(message, sizeof(message), stdin);
		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		//sendto �Լ� ȣ��� �� �ּ����� ���Ͽ� �Ҵ�
		sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));	//&serv_adr ���ؼ� �׻� ���� ������ �Ѱ���� �Ѵ�
		adr_sz = sizeof(from_adr);
		str_len = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_adr, &adr_sz);	//recvfrom ���ؼ� �׻� ��� �Դ��� �˷���� �Ѵ�

		message[str_len] = 0;	//���ڿ��� �������� �˷��ش�
		printf("Message from server: %s", message);
	}
	 
	close(sock);
	return 0;

}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}