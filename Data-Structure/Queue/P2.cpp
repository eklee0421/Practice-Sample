//<플레이어 카드 게임> 
//카드를 순서대로 비교하여 카드의 체력이 더 높을 때 승점 1점을 가져가며
// 최종적으로 승점이 높은 플레이어가 승리한다

#include <iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;

	for (int z = 0; z < t; z++) {
		
		int k = 0;
		cin >> k;

		int pp1 = 0;
		int pp2 = 0;

		int p1[10000] = {};
		int p2[10000] = {};
		
		for (int i = 0; i < k; i++) {
			cin >> p1[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> p2[i];
		}

		for (int j = 0; j < k; j++) {
			if (p1[j] > p2[j]) { 
				p1[j+1]= p1[j+1] + (p1[j] - p2[j] - 1);
				pp1++; 
			}
			else if (p1[j] < p2[j]) { 
				p2[j + 1] = p2[j + 1] + (p2[j] - p1[j] - 1);
				pp2++; 
			}
			else continue;
		}

		if (pp1 == pp2) cout << 0 << endl;
		else if (pp1 > pp2) cout << 1 << endl;
		else if (pp2 > pp1) cout << 2 << endl;
	}

}
