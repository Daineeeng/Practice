#include <iostream>
#include <queue>
using namespace std;

char miro[100][100];
bool visit[100][100];
int N, M, moveCnt;
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int x, int y) {
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty()) {
		int q_size = q.size();
		moveCnt++;

		while (q_size--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (cx == N - 1 && cy == M - 1) return;

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < M && !visit[nx][ny] && miro[nx][ny] == '1') {
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

	cin >> N >> M;
	moveCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> miro[i][j];
			visit[i][j] = 0;
		}
	}

	bfs(0, 0);

	cout << moveCnt << '\n';
	return 0;
}
