#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, hgt, ans;
int graph[100][100];
bool visit[100][100];
vector<int> v;
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int cx, int cy, int hgt) {

	q.push({ cx,cy });
	visit[cx][cy] = 1;

	while (!q.empty()) {

		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[nx][ny] && graph[nx][ny] > hgt) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	int max_height = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] >= max_height) {
				max_height = graph[i][j];
			}
		}
	}

	for (int hgt = 0; hgt <= max_height; hgt++) {

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] > hgt && !visit[i][j]) {
					bfs(i, j, hgt);
					cnt++;
				}
			}
		}

		v.push_back(cnt);
	}

	ans = *max_element(v.begin(), v.end());

	cout << ans << '\n';
	return 0;
}
