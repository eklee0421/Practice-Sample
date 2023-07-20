/*
"리스트 초기화"를 이용하여, 데이터 값이 변형되는 것을 막아주는 것
리스트형{ }으로 데이터 값을 넣어주면, 값이 변형되는 실수를 막아준다

방법1)
int (변수명) = { n };

방법 2)
int (변수명){ n };

예를 들어, int형에 실수를 넣으려고 할 경우 원래는 소수점 아래를 제거하고 넣어준다
하지만 리스트형으로 넣어줄 경우 컴파일 오류 발생

*/

#include <iostream>
using namespace std;

int main() {

	//int x = { 12.7 };         //이와 같이 int형에 넣으면 오류로 출력해줌
	//cout << x << endl;

	double d = { 12 };          // list intialization
	cout << "d는 "<< d << endl;

	unsigned int a = { 1 };
	int b{ 2 };

	cout << a << '+' << b << '=' << a + b << endl;
	
	return 0;
}
