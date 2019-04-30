#include <iostream>
using namespace std;
#define MAXN 1000
int N; int nums[MAXN];
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	freopen("Input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			if (nums[j] < nums[min]) min = j;
		}
		swap(nums[i], nums[min]);
	}
	for (int i = 0; i < N; i++) {
		cout << nums[i] << '\n';
	}
}
