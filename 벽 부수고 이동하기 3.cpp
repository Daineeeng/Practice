#include <iostream>
#include <queue>
using namespace std;

char graph[1000][1000];
bool visit[1000][1000][11];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct go {
	int x, y, wall;
};
queue<go> q;
int N, M, K, ans;
int dayCnt = 0;

int bfs() {
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;

	bool day = false;
	while (!q.empty()) {
		day = !day;
		++dayCnt;
		int q_size = q.size();

		while (q_size--) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cw = q.front().wall;
			q.pop();

			if (cx == N - 1 && cy == M - 1) {
				return dayCnt;
			}
			
			bool stay = false;
			for (int d = 0; d < 4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				int nw = cw + 1;

				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (graph[nx][ny] == '0') { // 벽 X
						if (!visit[nx][ny][cw]) {
							visit[nx][ny][cw] = true;
							q.push({ nx,ny,cw });
						}
					}
					else { // 벽 O
						if (!visit[nx][ny][nw] && cw < K) {
							if (day) { // 낮 -> 부수기
								visit[nx][ny][nw] = true;
								q.push({ nx,ny,nw });
							}
							else { // 밤 -> 머무르기
								stay = true;
							}
						}
					}
				}
			}
			if (stay) {
				q.push({ cx,cy,cw });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	cout << bfs() << '\n';
	return 0;
}
