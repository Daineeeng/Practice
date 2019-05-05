#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
