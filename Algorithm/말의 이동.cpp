#include <iostream>
#include <queue>
using namespace std;	

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;	//테스트 케이스의 수
	cin >> test;

	int dx[8] = { -2,-1,1,2,-2,-1,2,1 };
	int dy[8] = { -1,-2,-2,-1,1,2,1,2 };

	while (test--) {
		int dist[500][500] = {};	//장기판 방문 여부
		int l = 0; // 장기판의 크기 l*l
		cin >> l;

		int x = 0, y = 0;	//현재 장기말의 위치

		int startX = 0, startY = 0;	//처음 장기말의 위치
		cin >> startX >> startY;

		int finishX = 0, finishY= 0;
		cin >> finishX >> finishY;	//장기말이 도착할 좌표

		queue<int> qX;	//장기말이 갈 수 있는 X좌표 큐 생성
		qX.push(startX);
		queue<int> qY;	//장기말이 갈 수 있는 Y좌표 큐 생성
		qY.push(startY);

		dist[startX][startY] = 0;	//처음 방문한 곳은 0

		while (!qX.empty()) {
			
			x = qX.front();
			y = qY.front();
		
			qX.pop(); qY.pop();

			if (x == finishX && y == finishY) {
				cout << dist[finishX][finishY] << "\n";
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];

				if (nextX >= 0 && nextY >= 0 && nextX < l && nextY < l && dist[nextX][nextY] == 0) {
					dist[nextX][nextY] = dist[x][y] + 1;
					qX.push(nextX);
					qY.push(nextY);
				}
			}
		}
	}


}
