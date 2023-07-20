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
	if (b ==0) return a;
	else return eucl(b, a%b);
}
