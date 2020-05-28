#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	pid_t pid;	//프로세스 id 변수 저장

	pid = fork();	//자식 프로세스 생성

	if (pid == 0) {	//if child process
		puts("Hi I'am a child process");
	}
	else {   // if parent process
		printf("Child Process ID: %d \n", pid);
		sleep(30);	//sleep 30 sec - 이 30초동안 자식 프로세스는 좀비 프로세스 상태
	}
	if (pid == 0)
		puts("End child process");
	else
		puts("End parent process");

	return 0;
}