#include <iostream>
#include <string>
using namespace std;
int cnt[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << " ";
	}
	cout << '\n';
	return 0;
}
