#include <stdio.h>
#include <unistd.h>

int gval = 10;

int main(int argc, char *argv[]) {

	pid_t pid;	//프로세스 id 변수 저장
	int lval = 20;
	gval++, lval += 5; //gval==11, lval==25

	pid = fork();	//자식 프로세스 생성
	if (pid == 0)	//if child process
		gval += 2, lval += 2;	//자식이면 gval==13, lval==27
	else     // if parent process
		gval -= 2, lval -= 2;	//부모라면 gval==9, lval==23

	if (pid == 0)
		printf("Child Proc: [%d, %d] \n", gval, lval);
	else
		printf("Parent Proc: [%d, %d] \n", gval, lval);

	return 0;
}