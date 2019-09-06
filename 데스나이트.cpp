#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int visit[200][200];
int graph[200][200];
int dx[] = { -2,-2, 0, 0,+2,+2 };
int dy[] = { -1,+1,-2,+2,-1,+1 };
queue<pair<int, int>> q;
int N, r1, c1, r2, c2, minMove;

int bfs(int x, int y) {
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty()) {
		int q_size = q.size();
		minMove++;

		while (q_size--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			if (cx == r2 && cy == c2) return minMove;

			for (int k = 0; k < 6; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N >> r1 >> c1 >> r2 >> c2;

	memset(visit, 0, sizeof(visit));
	minMove = -1;
	
	int ans = bfs(r1, c1);
	cout << ans << '\n';

	return 0;
}
