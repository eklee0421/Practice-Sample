#include <iostream>
#include <string>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;
	cin >> test;

	int start[10000] = {};
	int end[10000] = {};

	for (int t = 0; t < test; t++) {

		int n = 0;	//개발하려는 아이템 수
		cin >> n;

		string str;

		for (int i = 0; i < n; i++) {
			cin >> str;
			cin >> start[i];
			cin >> end[i];
		}

		//종료 시점이 빠른 것부터 선택정렬
		for (int i = 0; i < n; i++) {
			int min = end[i];
			int item = i;
			for (int j = i; j < n; j++) {	//가장 작은 수 찾기
				if (min > end[j]) {
					min = end[j];
					item = j;
				}
			}
			end[item] = end[i];
			end[i] = min;
			int tmp = start[item];
			start[item] = start[i];
			start[i] = tmp;
		}

		int now = end[0];
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (now <= start[i]) {  //시작하면
				now = end[i]; //종료시점으로 업데이트
				cnt++;
			}
		}
		cout<< cnt << endl;
	}

}
