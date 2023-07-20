#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 100	//쓰레드의 개수 100개 만들 것

//쓰레드의 메인 함수들
void * thread_inc(void *arg);
void * thread_des(void *arg);

long long num = 0;
pthread_mutex_t mutex;	//뮤텍스 함수가 전역 변수로 호출

int main(int argc, char *argv[]) {

	pthread_t thread_id[NUM_THREAD];	//배열로 쓰레드 아이디 관리
	int i;

	pthread_mutex_init(&mutex, NULL);

	for (i = 0; i < NUM_THREAD; i++) {
		if(i%2)	//2로 나눴을 때 나머지가 1이면 thread_inc 가지고 쓰레드 생성
			pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
		else     //나머지가 0이면 thread_des 가지고 쓰레드 생성
			pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
	}

	for(i=0; i<NUM_THREAD;i++)
		pthread_join(thread_id[i], NULL);	

	printf("result: %lld \n", num);
	pthread_mutex_destroy(&mutex);
	return 0;
}

//각각의 쓰레드는 50번씩 호출 된다
void * thread_inc(void * arg) {	//하나의 쓰레드가 5천만번 1증가!!
	int i;
	pthread_mutex_lock(&mutex);	//뮤텍스 한번 잠금
							//다른 쓰레드가 모두 대기 상태로 놓여 있기 때문에 상황에 따라 단점으로 작용
							//그래도 보통은 이렇게 하는 게 성능에 유리하다
	for (i = 0; i < 50000000; i++)
		num += 1;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void * thread_des(void * arg) {
	int i;
		for (i = 0; i < 50000000; i++) {
			pthread_mutex_lock(&mutex);	//for문을 돌며 뮤텍스를 5천만번 잠그고 열어줘야 한다
		num -= 1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
