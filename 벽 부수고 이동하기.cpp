#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
char graph[1000][1000];
int visit[1000][1000][2]; // 0안부순거 1부순거
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


struct moving{
	int x;
	int y;
	int block;
};

queue<moving> q;


int bfs() {
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int block = q.front().block;
		q.pop();

		if (cx == N - 1 && cy == M - 1) {
			return visit[cx][cy][block];
		}

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (graph[nx][ny] == '1' && !visit[nx][ny][block] && !block) { // 벽O & 부순적 없음
					visit[nx][ny][block + 1] = visit[cx][cy][block] + 1;
					q.push({ nx,ny,block + 1 });
				}
				else if (graph[nx][ny] == '0' && !visit[nx][ny][block]) { // 벽X && 방문X
					visit[nx][ny][block] = visit[cx][cy][block] + 1;
					q.push({ nx,ny,block });
				}
			}
		}
	}
	return -1; // visit상태가 어떤지 디버깅
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	cout << bfs() << '\n';

	return 0;
}
