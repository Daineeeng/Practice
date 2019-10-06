#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int TC, ans, width;
int graph[1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		//init
		ans = 0;
		memset(graph, 0, sizeof(graph));
		cin >> width;
		for (int i = 0; i < width; i++) {
			cin >> graph[i];
		}
		
		//solve
		for (int i = 2; i <= width - 2; i++) {
			if (graph[i - 2] >= graph[i] || graph[i - 1] >= graph[i] || graph[i + 1] >= graph[i] || graph[i + 2] >= graph[i]) continue;
			int maxH = max(graph[i - 2], max(graph[i - 1], max(graph[i + 1], graph[i + 2]) ) );
			ans += graph[i] - maxH;

		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
