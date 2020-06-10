#include <iostream>
using namespace std;

int cnt = 0;

void DFS(int node, int graph[], bool visit[], bool finish[]) {
	visit[node] = 1;
	int nextnode = graph[node];

	if (visit[nextnode] == 0) DFS(nextnode, graph, visit, finish);
	else if (finish[nextnode] == 0) {
		while (nextnode != node) {
			cnt++;
			nextnode = graph[nextnode];
		}
		cnt++;	//자기자신으로 돌아오는 edge
	}
	finish[node] = 1;	
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;	//테스트 케이스의 수
	cin >> test;

	while (test--) {
		int n = 0;	//수강생의 수
		cin >> n;

		cnt = 0;

		int graph[10001] = {};	//각 index의 학생들이 원하는 친구
		for (int i = 1; i <= n; i++) cin >> graph[i];

		bool visit[10001] = {};	//dfs를 진행하면서 그 정점이 dfs에 의해 방문되었는지의 여부 판단
		bool finish[10001] = {};	//cycle에 들어갈 수 있음 (혹은 없음)이 확실시 되면 더이상 볼 필요 없다 

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) DFS(i, graph, visit, finish);
		}

		cout << n - cnt << "\n";

	}

}
