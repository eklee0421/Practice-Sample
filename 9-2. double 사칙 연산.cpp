/*

나누기 할 때 소수점까지 구하고 싶다면 double형을 이용한다
(다만, 이럴 경우 나머지 연산 불가능)  

*/

#include <iostream>
using namespace std;      

int main() {
	
	double a = 7;
	double b = 3;

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a / b << endl;
	//cout << a % b << endl;  -> 불가능
}
