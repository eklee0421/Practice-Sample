#include<iostream>
using namespace std;

int main() {

	int a = 90;
	bool b = true;

	cout << "bool 값은 : " << b << endl;

	if (b) {			//if의 조건이 만족(=1)일 경우 수행
		cout << "if의 값은 true" << endl;
	}

	if (a >= 90) {
		cout << "a는 90보다 크다." << endl;
	}

	else {
		cout << "a는 90보다 작다." << endl;
	}
}
