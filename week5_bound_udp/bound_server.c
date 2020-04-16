#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int serv_sock;	//���� ��ũ���ͷ� �����ϱ� ������ �� ���� ��ũ���͸� ������ ����
	char message[BUF_SIZE];	//data�� ������ ����
	struct sockaddr_in my_adr, your_adr;
	socklen_t adr_sz;
	int str_len, i;	//������ data�� ���̸� ������ ����

	if (argc != 2) {	
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_DGRAM, 0);	//SOCK_DGRAM�� ����ϸ� �񿬰��������� UDP ���� ����
	if (serv_sock == -1)
		error_handling("UDP socket creation error");

	//���� �ּ������� ���� ����ü �ʱ�ȭ
	memset(&my_adr, 0, sizeof(my_adr));
	my_adr.sin_family = AF_INET;
	my_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_adr.sin_port = htons(atoi(argv[1]));
	
	if (bind(serv_sock, (struct sockaddr*)&my_adr, sizeof(my_adr)) == -1)	//�������� �Ǿ���� �ϴ� �����̱� ������ �ּҸ� �Ҵ����־�� �Ѵ�
		error_handling("bind() error");
		
	for (i = 0; i < 3; i++) {

		sleep(5);	//delay 5 sec.
		adr_sz = sizeof(your_adr);	//data �߽����� ������ ���� ����
		str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&your_adr, &adr_sz);
		printf("Mesaage %d: %s \n", i + 1, message);
	}

	close(serv_sock); 
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}