#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int status;	//wait �Լ��� ���ڷ� ���� �ڽ� ���μ����� ���� ���³� ��ȯ�� �� ������ ����
	pid_t pid = fork();	//ù��° �ڽ� ����

	if (pid == 0) {	//ù ��° �ڽ��� return 3�� ������ 3�̶�� �� ��ȯ�ϰ� ����
		return 3;
	}
	else {	//�θ��
		printf("Child PID: %d \n", pid);	//ù��° �ڽ��� pid�� ����ϰ� 
		pid = fork();	//�ι�° �ڽ��� ����
		if (pid == 0) {	//�� ��° �ڽ� ���� �ü������ 7�� �����ϰ� ����
			exit(7);
		}
		else {	//�θ��
			printf("Child PID: %d \n", pid);	//�ι�° �ڽ� ���μ����� id ����ϰ� 
			wait(&status);	//�շ�� �ڽ� ���μ����� �ִ��� �˾ƺ���
			if (WIFEXITED(status))	//���������� ���� �Ǿ��ٸ� ���޵� ���� �������� ���
				printf("Child send one: %d \n", WEXITSTATUS(status));
			wait(&status);	//�ռ� �ڽ� ���� �ٸ� �ڽ��� ������ ���μ����� �ִ��� Ȯ��
			if (WIFEXITED(status))	//���� ������� ���������� ����Ǿ��ٸ� ���޵� �� ���
				printf("Child send two: %d \n", WEXITSTATUS(status));
			sleep(30);	//Sleep 30 sec	- ū �ǹ� ���� ����
		}
	}


	return 0;
}