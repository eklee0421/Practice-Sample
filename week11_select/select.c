#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 30

int main(int argc, char *argv[]) {

	/*reads - data 수신 여부에 관심있는 소켓이나 파일 디스크립터 등록(설정)
	  temps - select 함수 호출 이후에 등록된 파일 디스크립터 리스트 변화가 있는 것만 1로 남기고 나머지는 0으로 만들어줘야 하므로
			reads를 복사해서 temps를 넘겨준다!
	*/
	fd_set reads, temps;

	//result - select 함수의 반환 값 저장
	//str_len - data를 얼마나 읽어왔는지 확인 할 변수
	int result, str_len;
	char buf[BUF_SIZE];
	struct timeval timeout;

	FD_ZERO(&reads);
	FD_SET(0, &reads);	//0 is standard input(console)
	
	/*
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;
	-> select 함수가 호출되고 난 뒤 timeout이 발생하기까지 남았던 시간으로 바뀐다
	-> 따라서 select 함수를 호출하기 전에 매번 구조체 변수를 초기화 해주어야하기 때문에 
	   while문 안에 선언해주어야 한다
	-> 밖에 선언하면 timeout.tv_sec이 select 함수 호출 되고 난 이후 0으로 바뀌게 되면, 무조건 timeout 이 발생해 버린다!
	*/

	while (1) {
		temps = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;

		result = select(1, &temps, 0, 0, &timeout);	
		//첫번째 인자에 1이 들어가서 우리가 관찰하고 싶은 대상이 한개라는 것 알려줌
		//data 입력에만 관심이 있으므로, readset 자리에 temps가 들어가서 temps에 등록되어 있는 파일 디스크립터의 data 수신 여부 관찰
		//timeout이 설정되어 있어서, 시간이 다 될 동안 표준 입력을 통한 변화가 없으면 0을 반환
		//만약 변화가 있다면 변환한 개수만큼 반환

		if (result == -1) {
			puts("select() == error!");
			break;
		}
		else if (result == 0) {
			puts("Time-out!");
		}
		else {
			if (FD_ISSET(0, &temps)) {	//어떤 파일 디스크립터가 변경이 있었는지 확인 - 첫번째 인자에 파일디스크립터 넣어주면 된다
				str_len = read(0, buf, BUF_SIZE);	//변경된 내용 읽어와서 버퍼에 저장
				buf[str_len] = 0;
				printf("message from console: %s \n", buf);
			}
		}
	}
	
	return 0;
}