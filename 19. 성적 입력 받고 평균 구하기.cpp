#include <iostream>
using namespace std;

int main() {

	int total = 0;
	unsigned int cnt = 1;

	while (cnt <= 5) {
		cout << "성적 입력(" << cnt << "/5): ";
		
		int grade = 0;
		cin >> grade;
		
		total = total + grade;

		cnt++;
	}

	int avg = total / 5;
	
	cout << "Total: " << total << endl;
	cout << "Avg: " << avg << endl;
	
}
