#include <stdio.h>
#include <pthread.h>
void* thread_summation(void *arg);	//쓰레드 메인 역할을 하는 함수

int sum = 0;	//공유되는 메모리로 될 전역 변수

int main(int argc, char *argv[]) {

	pthread_t id_t1, id_t2;	//쓰레드 id 저장
	int range1[] = { 1,5 };	//덧셈의 범위 저장 1~5
	int range2[] = { 6,10 };	//6~10

	pthread_create(&id_t1, NULL, thread_summation, (void*)range1);	//첫번째 쓰레드의 아이디가 id_t1에 저장
	pthread_create(&id_t2, NULL, thread_summation, (void*)range2);	//마지막 인자가 메인함수에 인자로 들어간다!!!

	pthread_join(id_t1, NULL);	//각각 t1과 t2에 대한 쓰레드가 종료될 때까지 프로세스는 대기
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