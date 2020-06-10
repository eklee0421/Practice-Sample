#include <iostream>
using namespace std;

int main() {

  cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char arr[26][128] = {};	//코드워드들
	int hamming[26] = {};	//코드 워드들의 해밍 거리
	char incoding[1024] = {};

	int t = 0;
	cin >> t;
	
	for (int test = 0; test < t; test++) {

		int m = 0;	//알파벳의 갯수
		int n = 0;	//각 코드워드의 비트 수
		cin >> m >> n;
	
		//코드워드들 입력 받음
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		
		int b = 0;	//인코딩된 비트열의 길이
		cin >> b;
		//인코딩된 비트열을 입력 받음
		for (int i = 0; i < b; i++) {
			cin >> incoding[i];
		}

		for (int i = 0; i < b/n; i++) {
			int min = 1024;	//해밍거리가 가장 짧은 수
			int word = 0;	//가장 해밍거리가 짧은 알파벳
			
			for (int j = 0; j < m; j++) {
				int h = 0;	//해밍 거리
				for (int k = 0; k < n; k++) {
					if (incoding[n*i+k] != arr[j][k]) h++; 
				}
				hamming[j] = h;
			}

			for (int j = 0; j < m; j++) {
				if (min > hamming[j]) {
					min = hamming[j];
					word = j;
				}
			}

			cout << (char)(word + 65);
		}

		cout << "\n";
		
	}
}
