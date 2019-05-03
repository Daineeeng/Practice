#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, bfsCnt = 0;
int graph[100][100];
bool visit[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
vector<int> v;

void bfs(int i, int j) {
	int cnt = 0;
	q.push({ i,j });
	visit[i][j] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		visit[cx][cy] = 1;
		q.pop();
		++cnt;

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (0 <= nx && nx < M && 0 <= ny && ny < N && !visit[nx][ny] && !graph[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = M - y2; i < M - y1; i++) {
			for (int j = x1; j < x2; j++) {
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && !graph[i][j]) {
				bfs(i, j);
				bfsCnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << bfsCnt << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}
