//10과목의 성적을 입력 받고 통과 여부를 알려주는 프로그램

#include <iostream>
using namespace std;

int main() {

	int pass = 0;
	int fail = 0;
	int cnt = 0;
	
	while (cnt < 10) {
		cout << "pass는 1, fail은 2 입력: ";
		int in = 0;
		cin >> in;

		if (in == 1) {
			pass = pass + 1;

		}

		else if (in == 2) {
			fail = fail = 1;
		}
		else {
			cout << "잘못 입력했습니다" << endl;
			cnt = cnt - 1;
		}
		cnt = cnt + 1;
	}

	cout << "pass: " << pass << endl;
	cout << "fail: " << fail << endl;

	if (pass > 6) {
		cout << "시험 통과" << endl;
	}
	else {
		cout << "시험 실패" << endl;
	}
  
	return 0;
}
