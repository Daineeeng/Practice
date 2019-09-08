#include <iostream>
#include <algorithm>
using namespace std;

int level[15];
int N, L, R, X;
int ans = 0;

void solve(int minP, int maxP, int prob, int idx, int sumP) {
	if (prob >= 2) {
		if (L <= sumP && sumP <= R && maxP - minP >= X) {
			ans++;
		}
		if (prob == N) return;
	}
	for (int i = idx; i < N; i++) {
		solve(min(minP, level[i]), max(maxP, level[i]), prob + 1, i + 1, sumP + level[i]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("Input.txt", "r", stdin);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}

	solve(987654321, -987654321, 0, 0, 0);
	cout << ans << '\n';

	return 0;
}
