#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visit[1001];
queue<int> q;

void dfs(int start) {
	cout << start << ' ';
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next);
		}
	}
}

void bfs(int start) {


	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int now = q.front();
		cout << now << ' ';
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 1; i <= M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
	visit[V] = true;
	dfs(V);

	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
	cout << '\n';
	bfs(V);

	return 0;
}
