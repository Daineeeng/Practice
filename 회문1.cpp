#include <iostream>
#include <string>
using namespace std;

char pan[8][8];

int tc, TC, N, ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	for (tc = 1; tc <= 10; tc++) {
		cin >> N;
		ans = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> pan[i][j];
			}
		}
		// ㅡ
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				bool ok = true;
				for (int k = 0; k < (N / 2); k++) {
					if (pan[i][j + k] != pan[i][j + N - k - 1]) ok = false;
				}
				if (ok) ans++;
			}
		}
		// |
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				bool ok = true;
				for (int k = 0; k < (N / 2); k++) {
					if (pan[j + k][i] != pan[j + N - k - 1][i]) ok = false;
				}
				if (ok) ans++;
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
