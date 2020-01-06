//getline은 공백까지 포함해서 입력 받는다

#include<iostream>
#include<string>
using namespace std;

int main() {

	string msg;
	
	cout << "과목 입력: ";	

	getline(cin, msg);

	cout << "출력: " << msg << endl;
}
