#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int status;	//wait 함수에 인자로 들어가서 자식 프로세스의 종료 상태나 반환된 값 저장할 변수
	pid_t pid = fork();	//첫번째 자식 생성

	if (pid == 0) {	//첫 번째 자식은 return 3을 만나서 3이라는 값 반환하고 종료
		return 3;
	}
	else {	//부모는
		printf("Child PID: %d \n", pid);	//첫번째 자식의 pid를 출력하고 
		pid = fork();	//두번째 자식을 생성
		if (pid == 0) {	//두 번째 자식 또한 운영체제한테 7을 전달하고 종료
			exit(7);
		}
		else {	//부모는
			printf("Child PID: %d \n", pid);	//두번째 자식 프로세스의 id 출력하고 
			wait(&status);	//죵료된 자식 프로세스가 있는지 알아본다
			if (WIFEXITED(status))	//정상적으로 종료 되었다면 전달된 값이 무엇인지 출력
				printf("Child send one: %d \n", WEXITSTATUS(status));
			wait(&status);	//앞선 자식 말고 다른 자식이 종료한 프로세스가 있는지 확인
			if (WIFEXITED(status))	//같은 방법으로 정상적으로 종료되었다면 전달된 값 출력
				printf("Child send two: %d \n", WEXITSTATUS(status));
			sleep(30);	//Sleep 30 sec	- 큰 의미 없는 문장
		}
	}


	return 0;
}