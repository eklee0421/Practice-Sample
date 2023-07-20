/******************
***복리 계산 공식***
*******************

a = p ( 1 + r )^n
a : 총 금액
p : 처음에 넣은 돈의 액수
r : 이자율
n : year
제곱 함수 이용 pow(a,b)
= a^b를 의미한다.

헤더파일은 <cmath>이지만 <iostream>이 한 번에 가지고 오기 때문에 반드시 쓸 필요는 없다
**********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double amount = 0.0;
	double deposit = 1000.0;
	double rate = 0.05;

	cout << setw(5) << "Year" << setw(21) << "Amount on deposit" << endl;
	cout << setprecision(2) << fixed;         // 고정 소수점은 출력하기 전에만 표시해주면 됨

	for (int i = 1; i <= 10; i++) {
		amount = deposit * pow(1 + rate, i);
		cout << setw(5) << i << setw(21) << amount << endl;
	}
}
