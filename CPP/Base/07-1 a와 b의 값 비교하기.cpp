#include <iostream>
using namespace std;

int main() {
	int a = 10;                     //double은 64비트에 담고 int는 32비트에 담음
	int b = 20;

	cout << "a와 b는 다른 값인가?: " << (a != b) << endl;      // 1은 참/ 0은 거짓
				                       
	return 0;
}
