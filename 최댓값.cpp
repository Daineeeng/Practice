#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int maxN = 0; int maxidx = 1;
	for (int i = 1; i <= 9; i++) {
		int n; cin >> n;
		if (maxN < n) {
			maxN = n;
			maxidx = i;
		}
	}
	cout << maxN << '\n';
	cout << maxidx << '\n';
	return 0;
}
