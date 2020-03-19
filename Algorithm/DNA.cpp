/////////////////////////////////////////////////////////
각각의 종들의 해밍 거리를 파악하여 대표 서열을 만들고,
대표 서열과 각각의 종들의 해밍거리를 
/////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {

	int t = 0;	//테스트 케이스
	cin >> t;
	for (int test = 0; test < t; test++) {

		char arr[50][1000] = {};
		char str[1000] = {};
		int A[1000] = {};
		int T[1000] = {};
		int G[1000] = {};
		int C[1000] = {};
		
		int m = 0, n= 0;	//종의 갯수와 유전자 길이
		cin >> m >> n;

		// 각각의 종의 유전자 인풋
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				
				//해밍 거리의 합
				if (arr[i][j] == 'A') A[j]++;
				else if (arr[i][j] == 'T') T[j]++;
				else if (arr[i][j] == 'G') G[j]++;
				else if (arr[i][j] == 'C') C[j]++;
				
			}
		}

		for (int i = 0; i < n; i++) {
			int x = A[i];
			char y = 'A';

			if (x < C[i]) {
				x = C[i];
				y = 'C';
			}
			if (x < G[i]) {
				x = G[i];
				y = 'G';
			}
			if (x < T[i]) {
				x = T[i];
				y = 'T';
			}
			str[i] = y;
		}

		for (int i = 0; i < n; i++) {
			cout << str[i];
		}

    //대표 서열의 해밍 거리
		int h = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != str[j]) h++;
			}

		}
		cout << "\n" << h << "\n";
	}
}
