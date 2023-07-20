#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 100	//�������� ���� 100�� ���� ��

//�������� ���� �Լ���
void * thread_inc(void *arg);
void * thread_des(void *arg);

long long num = 0;

int main(int argc, char *argv[]) {

	pthread_t thread_id[NUM_THREAD];	//�迭�� ������ ���̵� ����
	int i;

	printf("sizeof long long: %d \n", sizeof(long long));

	for (i = 0; i < NUM_THREAD; i++) {
		if(i%2)	//2�� ������ �� �������� 1�̸� thread_inc ������ ������ ����
			pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
		else     //�������� 0�̸� thread_des ������ ������ ����
			pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
	}

	for(i=0; i<NUM_THREAD;i++)
		pthread_join(thread_id[i], NULL);	

	printf("result: %lld \n", num);
	return 0;
}

//������ ������� 50���� ȣ�� �ȴ�
void * thread_inc(void * arg) {	//�ϳ��� �����尡 5õ���� 1����!!
	int i;
	for (i = 0; i < 50000000; i++)
		num += 1;
	return NULL;
}

void * thread_des(void * arg) {
	int i;
	for (i = 0; i < 50000000; i++)
		num -= 1;
	return NULL;
}
