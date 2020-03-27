#include <iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);	

	int t = 0;
	cin >> t;

	for (int test = 0; test < t; test++) {
	
		char arr[225][225] = {};

		int row = 0; //행
		int column = 0; //열

		bool bw = 0;	//흑과 백
		bool W = 0;	//승패 결정 여부

		for (int k = 0; k < 225; k++){
			
			//cout << k << " ";

			int winR = 1;	//승패 확인하기 - 세로
			int winC = 1; // 가로
			int winD1 = 1;	//대각선1
			int winD2 = 1;	//대각선2

			//입력 받기
			cin >> row >> column;
			if (bw == 0) {
				arr[row][column] = 'b';	//'b'이면 흑
				bw = 1;
			}
			else {
				arr[row][column] = 'w';	//'w'이면 백
				bw = 0;
			}

			if (W == 1) continue;	//이미 승패가 결정난 경우 더 이상 진행하지 않음

			int i = row - 1; int j = column;
			//세로
			if (arr[row - 1][column] == arr[row][column]) {	
				while (arr[i][j] == arr[row][column]) {
					i--;
					winR++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			i = row + 1; j = column;
			if (arr[row+1][column] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					i++;
					winR++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			//cout << winR << " ";

			i = row; j = column - 1;
			//가로
			if (arr[row][column-1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j--;
					winC++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			i = row; j = column + 1;
			if (arr[row][column+1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j++;
					winC++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			//cout << winC << " ";

			i = row - 1; j = column - 1;
			//대각선1
			if (arr[row-1][column - 1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j--;
					i--;
					winD1++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			i = row + 1; j = column + 1;
			if (arr[row+1][column+1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j++;
					i++;
					winD1++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			//cout << winD1 << " ";

			i = row - 1; j = column + 1;
			//대각선2
			if (arr[row - 1][column + 1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j++;
					i--;
					winD2++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			i = row + 1; j = column - 1;
			if (arr[row + 1][column - 1] == arr[row][column]) {
				while (arr[i][j] == arr[row][column]) {
					j--;
					i++;
					winD2++;
					if (i == -1 || j == -1 || i == 225 || j == 225) break;
				}
			}
			//cout << winD2 << endl;

			if (winC == 5 || winD1 == 5 || winR == 5 || winD2 == 5) {
				cout << k + 1;
				if (bw == 0) cout << " W\n";
				else cout << " B\n";

				W = 1;
			}
		}
		
	}

}
