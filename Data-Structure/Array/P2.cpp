//배열을 입력 받고, 전체 값의 합과 평균을 구하는 예제
//3으로 나눴을 때 나머지가 각각 0,1,2인 배열끼리 한 

#include <iostream>
using namespace std;

int main() {

	int N = 0;
	cin >> N;

	int arr[100] = {};
	
	for (int n = 0; n < N; n++) {

		int M = 0;
		cin >> M;		

		int k = 0, j = 0, c = 0;
		int K = 0, J = 0, C = 0;

		for (int m = 0; m < M; m++) {
			cin >> arr[m];
		}

		for (int m = 0; m < M; m++) {
			if (m % 3 == 0) {
				k = k + arr[m];
				if (arr[m] != 0) K++;
			}
			else if (m % 3 == 1) {
				j = j + arr[m];
				if (arr[m] != 0) J++;
			}
			else if (m % 3 == 2) {
				c = c + arr[m];
				if (arr[m] != 0) C++;
			}
		}

		if (k == 0) K++;
		if (j == 0) J++;
		if (c == 0) C++;

		cout << k << " " << j << " " << c;
		cout << endl;
		cout << k / K << " " << j / J << " " << c / C;
		cout << endl;
	}
}
