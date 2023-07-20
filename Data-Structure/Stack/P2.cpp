//postfix로 들어온 연산식을 산하여 결과 출력하기

#include <iostream>
#include <string>
using namespace std;

int main() {

	int t = 0;
	cin >> t;

	for (int k = 0; k < t; k++) {
		
		int num[10000] = {};
		int t = -1;

		string str;

		cin >> str;

		int test = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '+') {
				test = num[t];
				t--;
				test = test + num[t];
				num[t] = test;
			}
			else if (str[i] == '*') {
				test = num[t];
				t--;
				test = test * num[t];
				num[t] = test;
			}
			else if (str[i] == '-') {
				test = num[t];
				t--;
				test = num[t] - test;
				num[t] = test;
			}
			else if (str[i] == '/') {
				test = num[t];
				t--;
				test = num[t] / test;
				num[t] = test;
			}
			else {
				t++;
				num[t] = str[i] - 48;
			}
		}

		cout << num[t] << endl;
	}

}
