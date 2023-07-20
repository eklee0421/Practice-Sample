/*

방법 1)
(데이터형)변수

방법 2)
static_cast<데이터형>(변수)
-> 방법 2는 c++ 14에서 가능

*/

#include <iostream>
using namespace std;

int main() {
	double d = 1.123;
	float f = 1.123f;

	int a = 100;
	int b = 3;

	d = static_cast<double>(a)/(b);     //a를 명시적으로 duuble형으로 바꿔줌
	cout << d << endl;

	int c = INT_MAX;                    //int형의 최대값
	cout << c << endl;

	unsigned int e = UINT_MAX;          //unsigend int형의 최대값
	cout << e << endl;

}
