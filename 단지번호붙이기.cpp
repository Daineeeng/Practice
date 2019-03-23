#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans, cnt;
char graph[25][25];
bool visit[25][25];
queue<pair<int, int>> q;
vector<int> v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int i, int j) {

	cnt = 0;
	q.push({ i,j });
	visit[i][j] = 1;

	while (!q.empty()) {

		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		cnt++;

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[nx][ny] && graph[nx][ny] == '1') {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && graph[i][j] == '1') {
				bfs(i, j);
				ans++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << ans << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
