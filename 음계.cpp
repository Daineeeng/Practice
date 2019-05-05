#include <iostream>
using namespace std;
int nums[8];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 8; i++) {
		cin >> nums[i];
	}
	bool asc = true;
	for (int i = 1; i < 8; i++) {
		if (nums[i] - nums[i - 1] == 1) {
			continue;
		} else if (nums[i] - nums[i - 1] == -1) {
			asc = false;
		}
		else {
			cout << "mixed" << '\n';
			return 0;
		}
	}
	if (asc) cout << "ascending" << '\n';
	else cout << "descending" << '\n';
	return 0;
}
