#include <iostream>
#include <algorithm>
//#include <cmath>
using namespace std;

int fac(int n) {
	int f = 1;
	for (int i = n; i > 0; i--) f *= i;
	return f;
}

long long pow(int x, int j) {
	long long k = 1;
	if (j == 0) x = 1;
	else if (j == 1) k = x;
	else {
		for (int i = j; i > 0; i--) {
			k *= x;
		}
	}
	return k;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;	//test case의 수
	cin >> test;

	while (test--) {
		int arr[9] = {};
		int n = 0;	//서로 다른 자연수의 개수
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int a = 0, b = 0;//특정 범위를 나타내는 수 a,b
		int x = 0;	//특정 수
		cin >> a >> b >> x;

		int cnt = 0;

		for (int i = 0; i < fac(n); i++) {
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				sum += (pow(x, j) * arr[j]);
			}
			sum %= 1013;
			
			if (sum >= a && sum <= b) cnt++;
			next_permutation(arr, arr + n);
		}
		cout << cnt << "\n";
	}
}
