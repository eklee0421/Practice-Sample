/*
현재 시각을 이용하여 랜덤수를 형성하는 프로그램

<cstdlib> : 랜덤함수를 가지고 옴
<ctime>: 현재 시각을 가지고 옴
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));       //time(0): 현재 시각을 초로 가지고 옴
                              //time(0)으로 가지고 온 값을 rand의 시드값으로 넣음

	for (int i = 0; i < 6; i++) {
		cout << rand()%3 << endl;
	}

}
