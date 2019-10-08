#include <iostream>
using namespace std;

int tc, TC;
long long N, L, R;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (tc = 1; tc <= TC; tc++) {
		cin >> N;
		L = 2 * N * N - 4 * N + 3;
		R = 2 * N * N - 1;

		cout << '#' << tc << ' ' << L << ' ' << R << '\n';
	}
	return 0;
}
