#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 30

int main(int argc, char *argv[]) {

	/*reads - data ���� ���ο� �����ִ� �����̳� ���� ��ũ���� ���(����)
	  temps - select �Լ� ȣ�� ���Ŀ� ��ϵ� ���� ��ũ���� ����Ʈ ��ȭ�� �ִ� �͸� 1�� ����� �������� 0���� �������� �ϹǷ�
			reads�� �����ؼ� temps�� �Ѱ��ش�!
	*/
	fd_set reads, temps;

	//result - select �Լ��� ��ȯ �� ����
	//str_len - data�� �󸶳� �о�Դ��� Ȯ�� �� ����
	int result, str_len;
	char buf[BUF_SIZE];
	struct timeval timeout;

	FD_ZERO(&reads);
	FD_SET(0, &reads);	//0 is standard input(console)
	
	/*
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;
	-> select �Լ��� ȣ��ǰ� �� �� timeout�� �߻��ϱ���� ���Ҵ� �ð����� �ٲ��
	-> ���� select �Լ��� ȣ���ϱ� ���� �Ź� ����ü ������ �ʱ�ȭ ���־���ϱ� ������ 
	   while�� �ȿ� �������־�� �Ѵ�
	-> �ۿ� �����ϸ� timeout.tv_sec�� select �Լ� ȣ�� �ǰ� �� ���� 0���� �ٲ�� �Ǹ�, ������ timeout �� �߻��� ������!
	*/

	while (1) {
		temps = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;

		result = select(1, &temps, 0, 0, &timeout);	
		//ù��° ���ڿ� 1�� ���� �츮�� �����ϰ� ���� ����� �Ѱ���� �� �˷���
		//data �Է¿��� ������ �����Ƿ�, readset �ڸ��� temps�� ���� temps�� ��ϵǾ� �ִ� ���� ��ũ������ data ���� ���� ����
		//timeout�� �����Ǿ� �־, �ð��� �� �� ���� ǥ�� �Է��� ���� ��ȭ�� ������ 0�� ��ȯ
		//���� ��ȭ�� �ִٸ� ��ȯ�� ������ŭ ��ȯ

		if (result == -1) {
			puts("select() == error!");
			break;
		}
		else if (result == 0) {
			puts("Time-out!");
		}
		else {
			if (FD_ISSET(0, &temps)) {	//� ���� ��ũ���Ͱ� ������ �־����� Ȯ�� - ù��° ���ڿ� ���ϵ�ũ���� �־��ָ� �ȴ�
				str_len = read(0, buf, BUF_SIZE);	//����� ���� �о�ͼ� ���ۿ� ����
				buf[str_len] = 0;
				printf("message from console: %s \n", buf);
			}
		}
	}
	
	return 0;
}