/*

while문

끝을 알 수 없을 때, 조건을 만족할 때까지 반복 (~~를 만족할 때까지)

*/


//1부터 10까지 더하기
#include <iostream>
using namespace std;

int main() {
	int p = 0;
	int sum = 0;

	while (p <= 100) {       //조건=100이 될 때까지
		sum = sum + p;
		p = p+1;	 //값 증가	
	}
	cout << "sum = " << sum << endl;

}
