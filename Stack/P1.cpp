//배열로 스택 구현하기

#include <iostream>
#include <string>
using namespace std;

int main() {

	int r = 0;
	cin >> r;
	string str;
	
	int arr[10000] = {};
	int t = -1;
	
	for (int i = 0; i < r; i++) {
		cin >> str;

		if (str == "push") {
			t++;
			cin >> arr[t];			
		}
		else if (str == "pop") {
			if (t == -1) cout << -1 << endl;
			else { 
				cout << arr[t] << endl; 
				t--;
			}
		}
		else if (str == "size") {
			cout << t + 1 << endl;
		}
		else if (str == "empty") {
			if (t == -1) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (str == "top") {
			if (t == -1) cout << -1 << endl;
			else cout << arr[t] << endl;
		}

	}
}
