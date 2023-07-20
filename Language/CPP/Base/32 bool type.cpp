/*
bool type

CPP에서 bool 타입은 true=1, false =0 으로 저장

만약 true,false로 출력하고 싶다면 boolalpha를 이용
*/

#include<iostream>
using namespace std;

int main() {

	bool a = true;
	bool b = false;
	cout << a << endl;
	cout << b << endl;

	cout << boolalpha << a << endl;
	cout << boolalpha << b << endl;
}
