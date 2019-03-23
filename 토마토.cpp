#include <iostream>
#include <queue>
using namespace std;

char graph[50][50];
int visit[50][50];
int dx[] = { -1,1,0,0 };
int dy[] = { -1,1,0,0 };
int R, C, moveCnt;

queue<pair<int, int>> hedge_q;
queue<pair<int, int>> water_q;

void bfs() {

	while (!hedge_q.empty()) {
		
		int wq_size = water_q.size();
		while (wq_size--) {
			int cx = water_q.front().first;
			int cy = water_q.front().second;
			water_q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < R && 0 <= ny && ny < C && graph[nx][ny] == '.') {
					graph[nx][ny] = '*';
					water_q.push({ nx,ny });
				}
			}
		}

		int hq_size = hedge_q.size();
		moveCnt++;

		while (hq_size--) {
			int cx = hedge_q.front().first;
			int cy = hedge_q.front().second;
			visit[cx][cy] = 1;
			hedge_q.pop();

			if (graph[cx][cy] == 'D') {
				cout << moveCnt - 1 << '\n';
				return;
			}

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < R && 0 <= ny && ny < C && !visit[nx][ny] && graph[nx][ny] == '.') {
					hedge_q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}

	}
	cout << "KAKTUS" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '*') {
				water_q.push({ i,j });
			}
			else if (graph[i][j] == 'S') {
				hedge_q.push({ i,j });
			}
		}
	}

	bfs();
	return 0;
}
