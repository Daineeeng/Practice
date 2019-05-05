#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int alphabet[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (65 <= s[i] && s[i] <= 90) alphabet[s[i] - 65]++;
		else if (97 <= s[i] && s[i] <= 122) alphabet[s[i] - 97]++;
	}

	int maxCnt = 0;
	for (int i = 0; i < 26; i++) {
		maxCnt = max(maxCnt, alphabet[i]);
	}

	int maxIdx = 0;
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == maxCnt) {
			cnt++;
			maxIdx = i;
			if (cnt >= 2) {
				cout << '?' << '\n';
				return 0;
			}
		}
	}
	cout << char(maxIdx + 65) << '\n';
	return 0;
}
