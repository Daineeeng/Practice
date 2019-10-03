#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[8];
bool visited[8];
vector<int> v;

void print() {
	for (int i = 0; i < M; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void dfs(int cnt) {
	if (cnt == M) {
		print();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			dfs(cnt + 1);

			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		arr[i] = i+1;
	}
	dfs(0);
	return 0;
}
