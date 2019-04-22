#include <iostream>
#include <algorithm>
using namespace std;

int N, M, sumN = 0;
float ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sumN += temp;
		M = max(M, temp);
	}
	ans = (float) (sumN * 100) / (M * N);
	cout << ans << '\n';
	return 0;
}
