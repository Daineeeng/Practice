#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("Input.txt", "r", stdin);
	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		string s; cin >> s;
		int sum = 0; int cnt = 1;
		for (int i = 0; i < s.length(); i++) {
			char now = s[i];
			if (now == 'O') {
				sum += cnt;
				cnt++;
			}
			else cnt = 1;
		}
		cout << sum << '\n';
	}
	return 0;
}
