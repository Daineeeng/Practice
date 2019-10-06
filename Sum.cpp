#include <iostream>
#include <memory.h>
#include <algorithm>
#define MAXN 100
using namespace std;

int graph[MAXN+2][MAXN+2];

int solve(int ans) {
	for (int i = 1; i <= MAXN; i++) {
		for (int j = 1; j <= MAXN; j++) {
			graph[i][101] += graph[i][j];
			graph[101][j] += graph[i][j];
			if (i == j) graph[101][101] += graph[i][j];
			if (i + j == 101) graph[0][101] += graph[i][j];
		}
	}
	for (int i = 0; i <= MAXN + 1; i++) {
		ans = max(ans, graph[i][101]);
	}
	for (int i = 1; i <= MAXN + 1; i++) {
		ans = max(ans, graph[101][i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans, tc;
	for (int i = 1; i <= 10; i++) {
		//init
		cin >> tc;
		memset(graph, 0, sizeof(graph));
		for (int i = 1; i <= MAXN; i++) {
			for (int j = 1; j <= MAXN; j++) {
				cin >> graph[i][j];

			}
		}

		//solve
		cout << "#" << tc << " " << solve(0) << "\n";
	}
	return 0;
}
