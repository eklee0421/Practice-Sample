/*

- AND연산
&& 이용
조건을 모두 충족 할 때 true를 출력한다

- OR연산
|| 이용
조건을 하나만 충족해도 true를 출력한다

*/

#include <iostream>
using namespace std;

int main() {

	int i = 1;

	if (3 < i && i < 7) {   //AND연산
		cout << "i는 3보다 크고 7보다 작다" << endl;
	}
	else {
		cout << "i는 3보다 크지 않고 7보다 작지 않다" << endl;
	}

	if (i < 3 || 7 < i) {   //OR연산
		cout << "i는 3보다 작거나 7보다 크다" << endl;
	}
	else {
		cout << "i는 3보다 작지 않거나 7보다 크지 않다" << endl;
	}

}
