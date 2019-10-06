#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

int ans, dump;
int graph[100];

bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		//init
		cin >> dump;
		for (int i = 0; i < MAXN; i++) {
			cin >> graph[i];
		}

		//solve
		int maxIdx, minIdx, maxH, minH;
		while (dump--) {
			maxH = 0; minH = 101; minIdx = 0; maxIdx = 0;
			for (int i = 0; i < MAXN; i++) {
				if (maxH < graph[i]) {
					maxIdx = i;
					maxH = graph[i];
				}
				if (minH > graph[i]) {
					minIdx = i;
					minH = graph[i];
				}
			}

			graph[maxIdx]--;
			graph[minIdx]++;
		}

		sort(graph, graph + MAXN, cmp);
		ans = graph[0] - graph[99];
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
