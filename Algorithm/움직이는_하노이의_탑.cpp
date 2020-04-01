#include <iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);	

	int t = 0;
	cin >> t;

	int arr[10000] = {};

	for (int test = 0; test < t; test++) {
	
		int n = 0; //원반의 개수
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int now = n;	//현재 내가 쌓아야하는 원반의 크기
		
		int j = 0;
		int cnt = 1;	//수레바퀴가 돌아야하는 수
		while (now != 0) {
			if (j == n) {
				j = 0;
				cnt++;
			}
			if (arr[j] == now) now--;
			j++;
		}

		cout << cnt << "\n";
	}
}
