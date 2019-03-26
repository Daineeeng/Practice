#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int zeroCnt = 0; 
int origin[100][100];
int graph[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M, virus_size, temp, ans = 0;

vector<int> ind;
vector<pair<int, int>> zeroCoor;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

void bfs() {
	temp = 0;

	for (int i = 0; i < virus_size; i++) {
		q.push({ virus[i].first, virus[i].second });

		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < M && graph[nx][ny] == 0) {
					q.push({ nx,ny });
					graph[nx][ny] = 2;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				temp++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			graph[i][j] = origin[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			origin[i][j] = graph[i][j];
			if (graph[i][j] == 0) {
				zeroCoor.push_back({ i,j });
				zeroCnt++;
			}
			else if (graph[i][j] == 2) {
				virus.push_back({ i,j });
				virus_size++;
			}
		}
	}

	for (int i = 0; i < zeroCnt - 3; i++) ind.push_back(0);
	for (int i = 0; i < 3; i++) ind.push_back(1);

	do {
		for (int i = 0; i < zeroCnt; i++) {
			if (ind[i] == 1) {
				graph[zeroCoor[i].first][zeroCoor[i].second] = 1;
			}
		}

		bfs();

		for (int i = 0; i < zeroCnt; i++) {
			if (ind[i] == 1) {
				graph[zeroCoor[i].first][zeroCoor[i].second] = 0;
			}
		}

		ans = max(temp, ans);
	} while (next_permutation(ind.begin(), ind.end()));

	cout << ans << '\n';

	return 0;
}
