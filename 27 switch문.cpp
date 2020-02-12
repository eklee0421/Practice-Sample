/*
선택문으로

if문이 조건을 하나씩 제거해나가는 것이었다면
switch문은 한 번에 해당 조건으로 찾아간다

*/

#include <iostream>
using namespace std;

int main() {

	int n = 0;
	cout << "성적 입력: ";
	cin >> n;
	
	switch (n/5) {
	case 19: 
		cout << "A+" << endl;
		break;
	case 18: 
		cout << "A0" << endl;
		break;
	case 17: 
		cout << "B+" << endl;
		break;
	case 16:
		cout << "B0" << endl;
		break;
	default:
		cout << "F" << endl;
		break;
	}
}
