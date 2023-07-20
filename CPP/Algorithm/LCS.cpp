#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;
	cin >> test;

	while (test--) {

		string x;	//첫번째 문자열
		string y; //두번째 문자열
		cin >> x >> y;

		int xy[1001][1001] = {};

		for (int i = 0; i < x.size(); i++) {
			for (int j = 0; j < y.size(); j++) {
				if (x[i] == y[j]) {
					xy[i + 1][j + 1] = xy[i][j] + 1;
					
				}
				else {
					if (xy[i + 1][j] > xy[i][j + 1]) {
						xy[i + 1][j + 1] = xy[i + 1][j];
					}
					else {
						xy[i + 1][j + 1] = xy[i][j + 1];
					}
				}
			}
		}
		cout << xy[x.size()][y.size()] << endl;
	}
}
