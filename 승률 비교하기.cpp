#include <iostream>
using namespace std;

int tc, TC, A, B, C, D;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (tc = 1; tc <= TC; tc++) {
		cin >> A >> B >> C >> D;

		cout << '#' << tc << ' ';
		if (A*D > B*C) cout << "ALICE";
		else if (A*D < B*C) cout << "BOB";
		else cout << "DRAW";
		cout << '\n';
	}
	return 0;
}
