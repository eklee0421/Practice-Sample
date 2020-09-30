#include <iostream>
using namespace std;

int eucl(int a, int b);

int main() {
	int a = 0, b = 0;
	cout << "두 수 입력: ";
	cin >> a >> b;

	int gcd = eucl(a, b);
	cout << gcd << endl;

	system("pause");
}

int eucl(int a, int b) {
	int temp = 0;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
