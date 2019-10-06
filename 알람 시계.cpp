#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int H,M;
	cin >> H >> M;
	if (H == 0) H = 24;
	if (M < 45) {
		M = M + 60 - 45;
		H--;
	}
	else {
		M -= 45;
	}
	cout << H << ' ' << M << '\n';
	return 0;
}
