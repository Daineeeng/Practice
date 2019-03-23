#include <iostream>
#include <queue>
using namespace std;

int TC, N;
bool visit[300][300];
int dx[] = { -1,-2,-2,-1,1,2, 2, 1 };
int dy[] = { -2,-1, 1, 2,2,1,-1,-2 };
queue<pair<int,int>> q;
int cx, cy, tx, ty, ans, moveCnt;

void bfs(int cx, int cy) {
	q.push({ cx,cy });
	visit[cx][cy] = 1;

	while (!q.empty()) {
		int q_size = q.size();
		moveCnt++;
		
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == tx && y == ty) {
				return;
			}

			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		moveCnt = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}

		while (!q.empty()) q.pop();

		cin >> cx >> cy;
		cin >> tx >> ty;
		bfs(cx, cy);

		cout << moveCnt << '\n';
	}

	return 0;
}
