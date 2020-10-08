/*
inline 함수:
함수가 반복문 밖에 선언 되어 있을 때 왔다갔다 하는 것이 더 오래 걸릴 경우 컴파일러가 반복문 안으로 코드 자체를 집어 넣음

넣을지 말지는 컴파일러가 결정하므로
in-line 함수를 사용해도 코드를 가져오지 않고 그냥 호출해서 이용하겠다고 결정할 수 있다

*/

#include <iostream>
using namespace std;

inline bool isEven(int i) {
		return i % 2==0;
}

inline double cube(const double side) {

	return side * side * side;
}

int main() {

	double num = 1.2;                       //1.2 * 1.2 * 1.2
	cout << cube(num) << endl;

	int sum = 0;
	for (int i = 0; i < 100; i++) {         //1부터 100까지 짝수만 더하기
		if (isEven(i)) {
			sum += i;
		}
	}
	cout << sum << endl;

//	system("pause");
}
