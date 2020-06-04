#include <stdio.h>
#include <pthread.h>
void* thread_summation(void *arg);	//������ ���� ������ �ϴ� �Լ�

int sum = 0;	//�����Ǵ� �޸𸮷� �� ���� ����

int main(int argc, char *argv[]) {

	pthread_t id_t1, id_t2;	//������ id ����
	int range1[] = { 1,5 };	//������ ���� ���� 1~5
	int range2[] = { 6,10 };	//6~10

	pthread_create(&id_t1, NULL, thread_summation, (void*)range1);	//ù��° �������� ���̵� id_t1�� ����
	pthread_create(&id_t2, NULL, thread_summation, (void*)range2);	//������ ���ڰ� �����Լ��� ���ڷ� ����!!!

	pthread_join(id_t1, NULL);	//���� t1�� t2�� ���� �����尡 ����� ������ ���μ����� ���
	pthread_join(id_t2, NULL);
	printf("result: %d \n", sum);
	return 0;
}

void* thread_summation(void *arg) {
	int start = ((int*)arg)[0];
	int end = ((int*)arg)[1];

	while (start <= end) {
		sum += start;
		start++;
	}
	return NULL;
}