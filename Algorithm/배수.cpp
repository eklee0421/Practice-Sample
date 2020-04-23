#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0; //테스트 케이스의 수
	cin >> test;

	while (test--) {

		string a;
		int b;
		cin >> a >> b;

		int an = a[0] - '0';
	
		int i = 1;
		while (i != a.size()) {
			if (an < b) {	//만약 나눌 수 없는 상태면 나눌 수 있을 수준의 큰 수로 만들어 준다
				an *= 10;
				an += (a[i] - '0');
				i++;
			}
			else {	//만약 나눌 수 있으면 나눠준다
				cout << an / b << endl;
				an %= b;
			}
		}

		if (an % b == 0) cout << 1 << endl;
		else cout << 0 << endl;

	}
}

