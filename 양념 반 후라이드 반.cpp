#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, X, Y;
int cost1, cost2, ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C >> X >> Y;
	ans = A * X + B * Y;
	if (X > Y) {
		cost1 = 2 * C * Y + A * (X - Y);
	}
	else {
		cost1 = 2 * C * X + B * (Y - X);
	}
	cost2 = C * 2 * max(X, Y);
	ans = min(ans, min(cost1, cost2));
	cout << ans << '\n';
	return 0;
}
