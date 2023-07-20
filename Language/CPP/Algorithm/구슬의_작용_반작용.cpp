#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int test = 0;
	cin >> test;

	while (test--) {
		int n = 0;	//구슬의 개수
		long long L = 0;	//길이 L
		int k = 0;	//k번째로 떨어지는 구슬

		cin >> n >> L >> k;

		long long biz[100000] = {};
		
		for (int i = 0; i < n; i++) {
			cin >> biz[i];
			if (biz[i] > 0) {
				biz[i] = L - biz[i];
			}
			else {
				biz[i] = 0 - biz[i];
			}
		}
		
		sort(biz, biz + n);

		cout << biz[k-1] << "\n";

	}
}
