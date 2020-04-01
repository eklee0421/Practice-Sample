#include <iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);	

	int t = 0;
	cin >> t;

	int arr[10001] = {};
	int index[10001] = {};

	for (int test = 0; test < t; test++) {
	
		int n = 0; //원반의 개수
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			index[arr[i]] = i;
		}
		
		int cnt = 0;	//수레바퀴가 돌아야하는 수
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				if (index[i] == n-1) cnt++;
			}
			if (index[i + 1] > index[i]) cnt++;
		}

		cout << cnt-1 << "\n";
	}
}
