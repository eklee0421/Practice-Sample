#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void * read(void * arg);
void * accu(void * arg);

//세마포어 참조 변수가 2개 선언
static sem_t sem_one;
static sem_t sem_two;
static int num;

int main(int argc, char *argv[]) {

	pthread_t id_t1, id_t2;
	sem_init(&sem_one, 0, 0);
	sem_init(&sem_two, 0, 1);

	//쓰레드 2개 생성
	pthread_create(&id_t1, NULL, read, NULL);
	pthread_create(&id_t2, NULL, accu, NULL);

	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);

	sem_destroy(&sem_one);
	sem_destroy(&sem_two);
	return 0;
}

void * read(void * arg) {	//5번 반복하면서 숫자를 입력받는 함수
	int i;

	for (i = 0; i < 5; i++) {
		fputs("Input num: ", stdout);

		sem_wait(&sem_two);	//공유하는 메모리인 num에 접근하기 전에 sem_wait 함수를 호출해서 두번째 세마포어 값을 1 감소 시켜 준다 (1->0)
		scanf("%d", &num);	
		sem_post(&sem_one);	//첫번째 세마포어의 값을 1 증가 시킨다	(0->1)
	}
	return NULL;
}

void * accu(void * arg) {
	int sum = 0, i;
	for (i = 0; i < 5; i++) {
		sem_wait(&sem_one); //(0->1->0) 위에서 1로 증가 시켜주기 전까지는 대기 상태에 놓이게 된다
		sum += num;
		sem_post(&sem_two);	//(0->1)
	}
	printf("Result: %d \n", sum);
	return NULL;
}