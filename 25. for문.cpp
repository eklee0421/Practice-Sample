/*
반복문으로 끝을 알 때 사용!

~~가 될 때까지 반복

종료조건은 무조건 1개이며, 다른 조건은 문장이 2개 이상 들어올 경우 ,(comma)로 구분
*/

//1에서 20까지 홀수만 더하는 프로그램

#include <iostream>
using namespace std;
 int main() {
 	int i = 0;
 	int sum = 0;

 	for (int i = 0; i <= 20; i++) {
 		if (i % 2 == 1) {
 			sum = sum + i;
 			cout << sum << " ";
 		}
 	}

 	cout << endl;

 }
