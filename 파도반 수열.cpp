#include <iostream>
using namespace std;

int TC, N;
long long Ns[101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		for (int i = 1; i <= 100; i++) {
			if (i < 3) {
				Ns[i] = 1;
			}
			else {
				Ns[i] = Ns[i - 2] + Ns[i - 3];
			}
		}
		cout << Ns[N] << '\n';
	}
	return 0;
}
