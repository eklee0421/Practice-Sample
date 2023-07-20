#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int status;		//종료 상태 저장
	pid_t pid = fork();		//자식 프로세스 생성

	if (pid == 0) {	//자식은
		sleep(15);	//15초동안 대기
		return 24;	//24반환하며 종료
	}
	else {		//부모는
		while (!waitpid(-1, &status, WNOHANG)) {	//자식프로세스의 종료 확인 ->  종료가 되지 않으면 반복
			sleep(3);
			puts("sleep 3sec.");
		}

		if (WIFEXITED(status))	//자식이 종료되면 반환된 값 출력
			printf("Child send %d \n", WEXITSTATUS(status));
	}

	return 0;
}