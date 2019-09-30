//배열로 queue 자료구조 만들기

#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[100001] = { };

	string str;
	int c = 0;
	cin >> c;

	int f = 0;
	int r = 0;

	for (int k = 0; k < c; k++) {
		cin >> str;

		if (str == "enqueue") {
			int x = 0;
			cin >> x;
			arr[r] = x;
			r++;
		}
		else if (str == "dequeue") {
			if (f == r) {
				cout << "Empty" << endl;
			}
			else {
				cout << arr[f] << endl;
				f++;
			}
		}
		else if (str == "size") {
			cout << r - f << endl;
		}
		else if (str == "isEmpty") {
			if (r == f) {
				cout << 1 << endl;
			}
			else cout << 0 << endl;
		}
		else if (str == "front") {
			if (f == r) {
				cout << "Empty" << endl;
			}
			else {
				cout << arr[f] << endl;
			}
		}
		else if (str == "rear") {
			if (f == r) {
				cout << "Empty" << endl;
			}
			else {
				cout << arr[r - 1] << endl;
			}
		}
	}
}
