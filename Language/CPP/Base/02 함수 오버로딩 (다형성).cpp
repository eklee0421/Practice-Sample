/*

함수 오버로딩 (function overloading): 동일한 함수의 이름을 중복해서 정의하는 것

c언어 : 함수의 이름만을 가지고 함수 호출
c++ : 함수 시그니쳐 = 함수 이름 + 매개변수 정보(개수, 타입) 을 가지고 함수 구별
    => C++에서 함수의 이름 혹은 매개변수 정보가 일치 하지 않으면 함수 오버로딩이 가능
       (C언어에서는 불가능 하다)

*/

#include <iostream>
using namespace std;

int f(int a) {
	cout << "정수 계산: ";
	return a*a;
	cout << endl;
}

double f (double a) {
	cout << "실수 계산: ";
	return a * a;
	cout << endl;
}


int main() {
	cout << f(20) << endl;       //int f()를 불러온다
	cout << f(10.2) << endl;     //double f()를 불러온다

}
