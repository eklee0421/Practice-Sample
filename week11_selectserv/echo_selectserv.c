#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 100
void error_handling(char *message);

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//��������-���� ��û�� �޴� ����, Ŭ���̾�Ʈ����-data �ۼ����� ���� ����
	char buf[BUF_SIZE];	//���� �� ���̴��� ��� char�� �迭
	int str_len, i;	//str_len: raed �Լ����� �� ���ڸ� �о�Դ��� �����ϴ� ����, i: �ݺ������� ���� ����(���� ��ũ����ó�� �̿뵵 ��)
	int fd_max, fd_num;	//fd_max: ���� ���� ū ���� ��ũ���� �ǹ�, fd_num: select �Լ��� ��ȯ�� ����
	struct timeval timeout;
	fd_set reads, cpy_reads;

	struct sockaddr_in serv_adr;	//�������Ͽ� �ּ����� �Ҵ� �� �� ���̴� ����ü
	struct sockaddr_in clnt_adr;	//accept�Լ� ���ڷ� �� ����ü - ���� ��û�� �� Ŭ���̾�Ʈ�� �ּ������� �Բ� ����
	socklen_t adr_sz;	//clnt_adr�� ũ�⸦ ����ִ� ����

	if (argc != 2) {	//���� ����� ���� ����ó�� ��� �ȳ�
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));	
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);	
	serv_adr.sin_port = htons(atoi(argv[1]));	
	
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)	
		error_handling("bind() error");
		
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	FD_ZERO(&reads);
	FD_SET(serv_sock, &reads);	//ó������ ���� ��� serv_sock�� �־��ְ� �ȴ�
	//ǥ�� �Է�, ǥ�� ���, ǥ�� ���� �� ���� ������ ���� ��ũ���� ����� - ������� 0 1 2 3 ���
	fd_max = serv_sock;	//fd_max == 3

	while (1) {
		cpy_reads = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;

		if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout)) == -1)
			break;	//���� �ߴٸ� �ٷ� break�ؼ� ������ �ȴ�
		
		if (fd_num == 0) 
			continue;	//0�̶�� while���� ó������ ���ư��� �ٽ�...
		

		for (i = 0; i < fd_max + 1; i++) {
			if (FD_ISSET(i, &cpy_reads)) {	//�ش� ���� ��ũ���Ϳ� ��ȭ�� �־����� Ȯ��
				if (i == serv_sock) {	//connection request! - ���� ���� ���Ͽ� ���� ��û�� ���Դٸ� ���� ���Ͽ� data �Է�! ���������� ���� 0
					adr_sz = sizeof(clnt_adr);
					clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);	//���� ���Ͽ����� accept�Լ��� ���ؼ� ���� ��û�����ϰ� ���ο� ����(���� ��ũ���ͷ�)
					
					/*�߿��� �κ�!*/
					FD_SET(clnt_sock, &reads);	//���� ���� ����(=data ������ ����)�� �����������!
					
					if (fd_max < clnt_sock)	//clnt_sock==4�� �ȴ� - ó���̶�� updata ���� �ʿ�
						fd_max = clnt_sock;
					printf("connected client: %d \n", clnt_sock);	//�ش� Ŭ���̾�Ʈ�� ����Ǿ��ٴ� �ȳ����� ���
				}
				else {	//read message! - ����� ���� ��ũ���Ͱ� �־���, �װ��� ���� ������ �ƴ϶��!
					str_len = read(i, buf, BUF_SIZE);
					if (str_len == 0) {	//close request! - �о�� data�� ���ٸ� Ŭ���̾�Ʈ���� data �ۼ��� ���� ��
						FD_CLR(i, &reads);	//���� ��󿡼� ����
						close(i);	//���� �ݾ��ֱ�
						printf("close client: %d \n", i);	//���� ���� �ȳ���
					}
					else {
						write(i, buf, str_len);	//echo! - �о�� data�� �ִٸ� 
					}
				}
			}
		}
	}
	close(serv_sock);
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}