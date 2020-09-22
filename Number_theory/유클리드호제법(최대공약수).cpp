#include <iostream>
using namespace std;

long long fun(long long a, long long b) {
	long long max = 0, min = 0;
	if (a > b) { max = a; min = b; }
	else { max = b; min = a; }

	if (max % min == 0) { return min; }
	else { max %= min; fun(max, min); }
}

int main() {

	int test = 0;
	cin >> test;

	while (test--) {
		long long a = 0, b = 0;
		cin >> a >> b;

		cout << fun(a, b) << endl;
	}
}
