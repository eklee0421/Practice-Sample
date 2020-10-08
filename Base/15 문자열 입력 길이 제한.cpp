#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cin >> str;
	string a;

	if (str.size() <= 5) {
		a = str;
		cout << a << endl;
	}
	else {
		a = str.substr(0, 5);
		cout << a << endl;
		cout << "글자가 너무 커요.." << endl;
	}

}
