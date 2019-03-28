#include <iostream>
#include <algorithm>
using namespace std;

int N, day, sum, ans = 0;
int T[15];
int P[15];

void solve(int day, int sum) {
	if (day == N) {
		ans = max(sum, ans);
		return;
	}
	if (day > N) return;
	solve(day + T[day], sum + P[day]); // 상담O
	solve(day + 1, sum); // 상담X
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	solve(0, 0);

	cout << ans << '\n';

	return 0;
}
