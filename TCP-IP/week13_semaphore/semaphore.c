#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void * read(void * arg);
void * accu(void * arg);

//�������� ���� ������ 2�� ����
static sem_t sem_one;
static sem_t sem_two;
static int num;

int main(int argc, char *argv[]) {

	pthread_t id_t1, id_t2;
	sem_init(&sem_one, 0, 0);
	sem_init(&sem_two, 0, 1);

	//������ 2�� ����
	pthread_create(&id_t1, NULL, read, NULL);
	pthread_create(&id_t2, NULL, accu, NULL);

	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);

	sem_destroy(&sem_one);
	sem_destroy(&sem_two);
	return 0;
}

void * read(void * arg) {	//5�� �ݺ��ϸ鼭 ���ڸ� �Է¹޴� �Լ�
	int i;

	for (i = 0; i < 5; i++) {
		fputs("Input num: ", stdout);

		sem_wait(&sem_two);	//�����ϴ� �޸��� num�� �����ϱ� ���� sem_wait �Լ��� ȣ���ؼ� �ι�° �������� ���� 1 ���� ���� �ش� (1->0)
		scanf("%d", &num);	
		sem_post(&sem_one);	//ù��° ���������� ���� 1 ���� ��Ų��	(0->1)
	}
	return NULL;
}

void * accu(void * arg) {
	int sum = 0, i;
	for (i = 0; i < 5; i++) {
		sem_wait(&sem_one); //(0->1->0) ������ 1�� ���� �����ֱ� �������� ��� ���¿� ���̰� �ȴ�
		sum += num;
		sem_post(&sem_two);	//(0->1)
	}
	printf("Result: %d \n", sum);
	return NULL;
}