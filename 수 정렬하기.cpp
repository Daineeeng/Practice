//Selection Sort

#include <iostream>
using namespace std;
#define MAXN 1000
int N; int nums[MAXN];
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (nums[j] < nums[i]) {
				swap(nums[i], nums[j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << nums[i] << '\n';
	}
}
