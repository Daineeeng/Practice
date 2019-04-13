#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, ans, sx, sy, timeCnt;
int s_size = 2; int ate = 0;
int graph[20][20];
bool visit[20][20];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q; // 상어
priority_queue <pair<int, int>> pq; // 물고기 x y

bool bfs() {
	while (!q.empty()) q.pop();
	while (!pq.empty()) pq.pop();
	memset(visit, 0, sizeof(visit));

	q.push({ sx,sy });
	visit[sx][sy] = 1;

	timeCnt = -1;
	while (!q.empty()) {
		int q_size = q.size();
		timeCnt++;
		
		while (q_size--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			
			if (graph[cx][cy] > 0 && graph[cx][cy] < s_size) pq.push({ -cx,-cy });

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[nx][ny]) {
					if (graph[nx][ny] <= s_size) {
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}
		}
		if (!pq.empty()) {
			sx = -pq.top().first;
			sy = -pq.top().second;
			graph[sx][sy] = 0;
			++ate;
			if (ate == s_size) {
				++s_size;
				ate = 0;
			}
			ans += timeCnt;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				graph[i][j] = 0;
				sx = i; sy = j;
			}
		}
	}

	while (bfs());
	cout << ans << '\n';
	return 0;
}
