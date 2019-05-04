#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check(string s) {
	int sLen = s.length();
	for (int i = 0; i < sLen; i++) {
		if (s[i] != s[sLen - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		string s, sr;
		cin >> s; sr = s;
		reverse(sr.begin(), sr.end());
		int sum = stoi(s) + stoi(sr);
		string sums = to_string(sum);
		if (check(sums)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
