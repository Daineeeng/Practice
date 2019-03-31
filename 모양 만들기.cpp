#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, cnt, ans;
int map[1000][1000];
int visit[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<point> q;
vector<point> zeros;

struct point {
	int x, y;
};

void bfs(int x, int y, int chk) {
	cnt = 0;

	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		visit[cx][cy] = chk;

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && visit[nx][ny] != chk && map[nx][ny]) {
				visit[nx][ny] = chk;
				q.push({ nx,ny });
			}
		}
		cnt++;
		q.pop();
	}

	if (cnt > ans)
		ans = cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zeros.push_back({ i,j });
			}
		}
	}

	int chk = 1;
	while (!zeros.empty()) {
		bfs(zeros.back().x, zeros.back().y, chk);
		zeros.pop_back();
		++chk;
	}

	cout << ans << '\n';
}
