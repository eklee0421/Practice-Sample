/*

헤더파일 <iomanip> 이용


cout << setprecision(n);
-> 전체에서 n번째까지 출력

cout << setprecision(n) << fixed; 
-> 소수점 아래 n번째까지 출력(n+1번째 자리에서 반올림 시켜준다)


입력 받은 성적의 합산 점수와 평균 출력
-1을 입력 하기 전까지 입력 받으며,
소수점 둘째 자리까지 출력하는 프로그램

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int total = 0;
	int cnt = 0;
	int grade = 0;

	while (grade != -1) {
		total = total + grade;
		cnt = cnt + 1;

		cout << "성적 입력(-1 종료): ";
		cin >> grade;
	}

	if (cnt != 0) {
		double avg = static_cast<double>(total) / cnt;
		cout << "Total: " << total << endl;
		cout << setprecision(2) << fixed;         //고정 소수점 두자리까지 찍음(반올림 해서 출력) 
		cout << "Avg: " << avg << endl;
	}
}
