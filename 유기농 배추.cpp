#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int ground[50][50];
bool visit[50][50];
queue<pair<int, int>> q;
int TC, ans;
int M, N, K;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int cx, int cy) {

	q.push({ cx,cy });
	visit[cx][cy] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
	
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (0 <= nx && nx < M && 0 <= ny && ny < N && visit[nx][ny] == 0 && ground[nx][ny] == 1) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		ans = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
				ground[i][j] = 0;
			}
		}

		int a, b;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			ground[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (ground[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
