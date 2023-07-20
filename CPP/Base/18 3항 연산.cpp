// 수의 비교는 대표적으로 if문을 이용하는 것과 삼항연산으로 하는 방법이 있다

#include<iostream>
using namespace std;

int main() {

	int n = 10;
	int m = 20;
	int max = (n > m) ? n : m;			// n > m이면 n 값, 아니면 m 값
	int min = (n < m) ? n : m;			// n < m이면 n 값, 아니면 m 값
	cout << max << "이 더 크다." << endl;
	cout << min << "이 더 작다." << endl;

	cout << ((n > m) ? n : m) << "이 더 크다" << endl;   // 우선 순위 때문에 괄호해주기
        cout << ((n < m) ? n : m) << "이 더 작다" << endl; 
}


/*/////////////////////////////////////////
/////////////if문으로 비교하기/////////////
/////////////////////////////////////////

#include<iostream>
using namespace std;

int main() {

	int n = 10;
	int m = 20;
	
	int max = 0;
	int min = 0;

	if (n > m) {
		max = n;
		min = m;
	}

	else {
		max = m;
		min = n;
	}

	cout << max << "이 더 크다." << endl;
	cout << min << "이 더 작다." << endl;

	cout << max << "이 더 크다." << endl;
	cout << min << "이 더 작다." << endl;
}

*/
