#include <iostream>
#include <memory.h>
using namespace std;

int nums[100]; long long sum;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		memset(nums, 0, sizeof(nums));
		sum = 0;
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				sum += gcd(nums[i], nums[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
