#include <iostream>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;

int N, L, R, ans;
int graph[50][50];
int united_idx[50][50];
int cnt[2501];
int sum[2501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int,int>> q;

void make_unite(int cx, int cy, int united_idx[][50], int unit_idx, int& cnt, int& sum) {
	q.push({ cx,cy });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		united_idx[cx][cy] = unit_idx;
		++cnt;
		sum += graph[cx][cy];

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			int diff = abs(graph[cx][cy] - graph[nx][ny]);
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (!united_idx[nx][ny] && L <= diff && diff <= R) {
					q.push({ nx,ny });
					united_idx[nx][ny] = unit_idx;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	ans = 0;

	bool update = true;
	while (update) {
		update = false;

		memset(united_idx, 0, sizeof((united_idx)));
		int unit_idx = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(sum, 0, sizeof(sum));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(united_idx[i][j] == 0) {
					// 시작점, 소속된 연합 번호, 연합 idx, 연합 국가수, 인구 총합
					++unit_idx;
					make_unite(i, j, united_idx, unit_idx, cnt[unit_idx], sum[unit_idx]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int index = united_idx[i][j];
				int avg = sum[index] / cnt[index];
				if (graph[i][j] != avg) {
					graph[i][j] = avg;
					update = true;
				}
			}
		}
		if (update) ++ans;
	}

	cout << ans << '\n';

	return 0;
}
