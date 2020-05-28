#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int status;		//���� ���� ����
	pid_t pid = fork();		//�ڽ� ���μ��� ����

	if (pid == 0) {	//�ڽ���
		sleep(15);	//15�ʵ��� ���
		return 24;	//24��ȯ�ϸ� ����
	}
	else {		//�θ��
		while (!waitpid(-1, &status, WNOHANG)) {	//�ڽ����μ����� ���� Ȯ�� ->  ���ᰡ ���� ������ �ݺ�
			sleep(3);
			puts("sleep 3sec.");
		}

		if (WIFEXITED(status))	//�ڽ��� ����Ǹ� ��ȯ�� �� ���
			printf("Child send %d \n", WEXITSTATUS(status));
	}

	return 0;
}