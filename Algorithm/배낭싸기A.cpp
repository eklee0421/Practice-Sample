#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;	//test case
	cin >> test;

	while (test--) {
		int n = 0;	//강인하가 소유하고 있는 물건의 개수
		int k = 0;	//배낭에 넣을 수 있는 총무게
		cin >> n >> k;

		int w[500] = {};	//각 물건의 무게
		int v[500] = {};	//각 물건의 가치
		int arr[500] = {};

		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		for (int i = 0; i < n; i++) {
			arr[i] = v[i] / w[i];
		}

		for (int i = 0; i < n; i++) {
			int max = i;
			for (int j = i; j < n; j++) {
				if (arr[max] < arr[j]) { 
					max = j;
				}
			}
			int tmp = arr[max];
			arr[max] = arr[i];
			arr[i] = tmp;

			int tmp1 = w[max];
			w[max] = w[i];
			w[i] = tmp1;

			int tmp2 = v[max];
			v[max] = v[i];
			v[i] = tmp2;
		}
    
		int i = 0;	//인덱스
		int weight = 0;	//현재까지 가방에 담긴 무게
		int total = 0;
		while (weight + w[i] <= k) {
			weight += w[i];
			total += v[i];
			i++;
			
			if (i == n) break;
		}

		if (i != n) {
			total += (v[i] / w[i])*(k - weight);
		}
		cout << total << endl;
	}
}
