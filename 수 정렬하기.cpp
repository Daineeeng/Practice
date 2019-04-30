// Selection Sort

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
		//cout << i + 1 << "단계 ";
		//for (int i = 0; i < N; i++) cout << nums[i] << " ";
		//cout << '\n';
	}
	for (int i = 0; i < N; i++) {
		cout << nums[i] << '\n';
	}
}


// Bubble Sort

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
	for (int i = N; i > 0; i--) {
		//cout << N - i + 1 << "단계\n";
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
			//for (int i = 0; i < N; i++) cout << nums[i] << " ";
			//cout << '\n';
		}
	}
	for (int i = 0; i < N; i++) {
		cout << nums[i] << '\n';
	}
}

