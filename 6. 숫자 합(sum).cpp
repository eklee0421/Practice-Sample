#include <iostream>
using namespace std;

int main() {
	int num1 = 0;
	int num2 = 0;

	cout << "숫자 두개를 입력하세요: ";
	cin >> num1 >> num2;

	int sum = num1 + num2;
	cout << "합은: " << sum << endl;

	system("pause");
	return 0;
}
