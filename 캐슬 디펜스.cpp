#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int N, M, D, cnt, enmx, enmy, ans = 0;
int ori[16][15];
int graph[16][15];
vector<int> ind;
queue<pair<int, int>> q;

void reset() {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			graph[i][j] = graph[i - 1][j];
		}
	}
	for (int i = 0; i < M; i++) graph[0][i] = 0;
}

bool targeting(int arcx, int arcy) { // 궁수가 쏠 적군을 찾으면 true
	priority_queue < pair<int, pair<int, int>>> pq;
	for (int enmx = N - 1; enmx >= N - D; enmx--) {
		for (int enmy = 0; enmy < M; enmy++) {
			if (graph[enmx][enmy] == 1) {
				int diff = (arcx - enmx) + abs(arcy - enmy);
				pq.push({ -diff,{ -enmy,-enmx } });
			}
		}
	}
	if (pq.empty() || -pq.top().first > D) return false;
	enmx = -pq.top().second.second;
	enmy = -pq.top().second.first;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ori[i][j];
		}
	}

	for (int i = 0; i < M - 3; i++) ind.push_back(0);
	for (int i = 0; i < 3; i++) ind.push_back(1);

	// 궁수 경우의 수마다
	do {
		int time = N;
		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = ori[i][j];
			}
		}

		for (int i = 0; i < M; i++) {
			if (ind[i] == 1) graph[N][i] = 2;
		}

		while (time--) {
			for (int i = 0; i < M; i++) {
				if (graph[N][i] == 2) {
					if (targeting(N, i)) { //true면 큐에 넣음
						q.push({ enmx, enmy });
					}
				}
			}

			while (!q.empty()) {
				int firstx = q.front().first;
				int firsty = q.front().second;
				q.pop();

				if (graph[firstx][firsty] == 1) {
					graph[firstx][firsty] = 0;
					cnt++;
				}
			}

			reset();
		}

		for (int i = 0; i < M; i++) {
			if (graph[N][i] = 2) graph[N][i] = 0;
		}

		ans = max(ans, cnt);
	} while (next_permutation(ind.begin(), ind.end()));
	cout << ans << '\n';
	return 0;
}
