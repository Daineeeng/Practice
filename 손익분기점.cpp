#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long A, B, C;
	cin >> A >> B >> C;
	int ans = 1;
	long long diff = C - B;
	if (diff <= 0) cout << -1 << '\n';
	else cout << (A / diff) + 1 << '\n';
	return 0;
}
