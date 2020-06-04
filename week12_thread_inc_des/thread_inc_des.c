#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 100	//쓰레드의 개수 100개 만들 것

//쓰레드의 메인 함수들
void * thread_inc(void *arg);
void * thread_des(void *arg);

long long num = 0;

int main(int argc, char *argv[]) {

	pthread_t thread_id[NUM_THREAD];	//배열로 쓰레드 아이디 관리
	int i;

	printf("sizeof long long: %d \n", sizeof(long long));

	for (i = 0; i < NUM_THREAD; i++) {
		if(i%2)	//2로 나눴을 때 나머지가 1이면 thread_inc 가지고 쓰레드 생성
			pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
		else     //나머지가 0이면 thread_des 가지고 쓰레드 생성
			pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
	}

	for(i=0; i<NUM_THREAD;i++)
		pthread_join(thread_id[i], NULL);	

	printf("result: %lld \n", num);
	return 0;
}

//각각의 쓰레드는 50번씩 호출 된다
void * thread_inc(void * arg) {	//하나의 쓰레드가 5천만번 1증가!!
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
