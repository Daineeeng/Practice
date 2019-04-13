#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, nx, ny, year = -1;
bool visit[300][300];
int graph[300][300];
int temp[300][300];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct ice {
	int x, y;
};
queue<ice> q;

void bfs(int x, int y) {
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty()) {
		int melt = 0;
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !visit[nx][ny]) {
				if (graph[nx][ny] == 0) {
					++melt;
				}
				else {
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
		if (melt >= graph[cx][cy]) temp[cx][cy] = 0;
		else temp[cx][cy] = graph[cx][cy] - melt;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	while (1) {
		++year;
		int group = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] != 0 && !visit[i][j]) {
					bfs(i, j);
					++group;
				}
			}
		}
		if (group == 0) break;
		if (group >= 2) {
			cout << year << '\n';
			return 0;
		}
		memcpy(graph, temp, sizeof(graph));
		memset(temp, 0, sizeof(temp));
	}
	cout << 0 << '\n';
	return 0;
}
