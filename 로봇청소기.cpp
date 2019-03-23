#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int graph[50][50];
int visit[50][50];
int dx[] = { -1,0,1,0 }; //북동남서
int dy[] = { 0,1,0,-1 };
int N, M, r, c, d, moveCnt = 1;

void move(int cx, int cy, int cd) {
	while (true) {
		visit[cx][cy] += 1;
		bool turnFin = true;

		for (int i = 1; i < 5; i++) { // 왼쪽 탐색
			int	nd = (cd + 3 * i) % 4; //회전 셋팅
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (nx < 0 || nx <= N && ny < 0 && ny <= M) continue;

			if ((visit[nx][ny]==0) && !graph[nx][ny]) { // 청소할 곳 O
				// 회전
				cx = nx;
				cy = ny;
				cd = nd;
				turnFin = false;
				moveCnt++;
				break;
			} else { // 청소할 곳 X -> 다시 왼쪽 탐색
				continue;
			}
		}

		if (turnFin == true) { // 4방향 다 (청소 끝 || 벽)
			// 후진 셋팅
			cx = cx - dx[cd];
			cy = cy - dy[cd];
			if (cx < 0 || cx <= N && cy < 0 && cy <= M) continue;

			if (!graph[cx][cy]) { // 뒤가 벽이 아니면
				// 후진
			}
			else if (graph[cx][cy]) { // 뒤가 벽이면
				// 종료
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	memset(graph, 0, sizeof(graph));
	memset(visit, 0, sizeof(visit));

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	move(r, c, d);

	cout << moveCnt << '\n';

	return 0;
}
