//배열에 원소 추가하고 빼기

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int m = 0;
	cin >> m;
	
	int arr[10000] = {};

	for (int M = 0; M < m; M++) {

		cin >> str;

		if (str == "at") {
			int i = 0;
			cin >> i;
			if (arr[i] == 0) cout << 0 << endl;
			else cout << arr[i] << endl;
		}
		else if (str == "set") {
			int i, x;
			cin >> i >> x;
			if (arr[i] == 0) cout << 0 << endl;
			else arr[i] = x;
		}
		else if (str == "add"){
			int i,x;
			cin >> i >> x;
			if (arr[i] == 0) {
				for (int I = 0; I < 10000; I++) {
					if (arr[I] == 0) {
						arr[I] = x;
						break;
					}
				}
			}
			else {
				for (int I = 10000 - 2; I >= i; I--) {
					arr[I + 1] = arr[I]; 
				}
				arr[i] = x;
			}
		}
		else if (str == "remove") {
			int i;
			cin >> i;
			if (arr[i] == 0) cout << 0 << endl;
			else {
				cout << arr[i] << endl;
				for (int I = i; I < 10000-1; I++) {
					arr[I] = arr[I + 1];
				}
			}
		}
		else if (str == "printArray") {
			if (arr[0] == 0) cout << 0 << endl;
			else {
				for (int i = 0; arr[i] != 0; i++) {
					cout << arr[i] << " ";
				}
				cout << endl;
			}
		}
	}
}
