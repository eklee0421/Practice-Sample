#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;
	cin >> test;

	while (test--) {
		
		int n = 0;	//총 날짜의 수
		int d = 0;	//고려할 지출 날짜 범위

		cin >> n >> d;

		int ex[201] = {};
		int day[200000] = {};
		int alram = 0;

		for (int i = 0; i < n; i++) {
			cin >> day[i];
			if (i < d)
				ex[day[i]]++;
		}

		for (int i = d; i < n; i++) {
			int cnt = 0;
			int j = 0;
			if (d % 2 == 0) {	//짝수라면
				while (1) {
					cnt += ex[j];
					if (cnt == d / 2) {
						int a = j + 1;
						while (ex[a] == 0) a++;
						if ((j + a) <= day[i]) alram++;
						break;
					}
					else if(cnt > d / 2){
						if ((j + j) <= day[i]) alram++;
						break;
					}
					j++;
				}
			}
			else {	//홀수라면
				while (1) {
					cnt += ex[j];
					if (cnt >= d / 2 + 1) {
						if ((j + j) <= day[i]) alram++;
						break;
					}
					j++;
				}
			}
			ex[day[i - d]]--;
			ex[day[i]]++;
		}

		cout << alram << endl;
	}
}
