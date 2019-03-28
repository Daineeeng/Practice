#include <iostream>
#include <queue>
using namespace std;

int N, ans = 0;
int graph[16][16];

// 0가로 1대각선 2세로
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };

struct pipe {
	int x;
	int y;
	int dir;
};
queue<pipe> q;

void bfs() {
	q.push({ 0,1,0 });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dir;
		q.pop();

		if (cx == N - 1 && cy == N - 1) {
			ans++;
		}

		if (cd == 0) { // 가로->가로,대각선
			for (int k = 0; k < 2; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				int nd = k;
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !graph[nx][ny]) {
					if (nd == 1 && !graph[nx-1][ny] && !graph[nx][ny-1]) { // 대각선
						q.push({ nx,ny,nd });
					}
					else if (nd != 1) { // 가로
						q.push({ nx,ny,nd });
					}
				}
			}
		}
		else if (cd == 1) { // 대각선->가로,대각선,세로
			for (int k = 0; k < 3; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				int nd = k;
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !graph[nx][ny]) {
					if (nd == 1 && !graph[nx - 1][ny] && !graph[nx][ny - 1]) { // 대각선
						q.push({ nx,ny,nd });
					}
					else if (nd != 1) { // 가로, 세로
						q.push({ nx,ny,nd });
					}
				}
			}
		}
		else if (cd == 2) { // 세로->대각선,세로
			for (int k = 1; k <= 2; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				int nd = k;
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !graph[nx][ny]) {
					if (nd == 1 && !graph[nx - 1][ny] && !graph[nx][ny - 1]) { // 대각선
						q.push({ nx,ny,nd });
					}
					else if (nd != 1 ) { // 가로, 세로
						q.push({ nx,ny,nd });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	bfs();

	cout << ans << '\n';

	return 0;
}
