/*

만약 int/int를 할 경우에 double에 저장해도 int형으로 계산된다
계산 할 당시에 int형 범위 안에 계산 한 뒤 저장만 double에 하기 때문!

*/

#include <iostream>
using namespace std;

int main() {
	double d = 1.123;
	int a = 100;
	int b = 3;

	d = a / b;              // (int) / (int)
	cout << d << endl;

}
