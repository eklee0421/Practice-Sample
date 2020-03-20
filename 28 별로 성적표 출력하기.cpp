/*
cin은 공백과 엔터는 입력 종료로 간주한다

get함수는 문자를 입력 받는다

getline은 문자열을 입력 받음
*/

//성적표를 *로 출력

#include <iostream>
using namespace std;

int main () {

	int grade;
	cout << "성적 입력(A~F)/ 종료는 Ctrl+z:";

	static int aCnt;
	static int bCnt;
	static int cCnt;
	static int dCnt;
	static int fCnt;

	while ((grade = cin.get()) != EOF) {       //get함수로 입력 받은 값 넣음
		
		switch (grade) {
		case'A':
		case'a':
			aCnt++;
			break;
		case'B':
		case'b':
			bCnt++;
			break;
		case'C':
		case'c':
			cCnt++;
			break;
		case'D':
		case'd':
			dCnt++;
			break;
		case'F':
		case'f':
			fCnt++;
			break;
		case '\n':
		case '\t':
		case ' ':
			break;
		default:
			cout << "잘못된 입력" << endl;
			break;

		}

	}

	cout << "======성적표=======" << endl;
	cout << "A: ";
	for (int i = 0; i < aCnt; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "B: ";
	for (int i = 0; i < bCnt; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "C: ";
	for (int i = 0; i < cCnt; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "D: ";
	for (int i = 0; i < dCnt; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "F: ";
	for (int i = 0; i < fCnt; i++) {
		cout << "*";
	}
	cout << endl;
}
