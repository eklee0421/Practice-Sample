#include <iostream>
using namespace std;

int main() {

	int year = 365;
	int day = 24;
	int minute = 60;
	int second = 60;
	long long int millisec = 1000;
	long long int nanosec = 1000000000;

	unsigned long long int x = year * day * minute * second * millisec;   //명시적인 형변환을 해주는 것이 좋다
	unsigned long long int y = year * day * minute * second * nanosec;
	cout << "1년은 " << x << " 밀리초 입니다" << endl;
	cout << "1년은 " << y << " 나노초 입니다" << endl;
	
}
