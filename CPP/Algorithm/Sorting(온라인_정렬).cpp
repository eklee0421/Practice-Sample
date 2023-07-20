#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;
	cin >> test;

	while (test--) {
		long long slot[101] = {};
		int m = 0; //슬롯의 개수
		cin >> m;
		int size = 0;	//사이즈의 범위
		cin >> size;

		int score[10001] = {};	//구간별 점수

		for (int i = 1; i <= m; i++) cin >> score[i];	//각 구간별 점수

		for (int i = 0; i < m; i++) {
			long long num = 0;	//삽입 될 수
			int index = 0;	//삽입될 슬롯의 위치
			cin >> num >> index;
			slot[index] = num;
		}

		int cnt = 1;	//구간별 사이즈
		int total = 0;	//최종 점수
		for (int i = 1; i <= m; i++) {
			if (i == m) {
				total += score[cnt];
			}
			else if (slot[i] < slot[i + 1]) {
				cnt++;
			}
			else {
				total += score[cnt];
				cnt = 1;
				
			}
		}
		cout << total << "\n";

	}
}
