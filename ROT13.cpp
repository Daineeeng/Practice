#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (('A' <= s[i] && s[i] <= 'A' + 12) || ('a' <= s[i] && s[i] <= 'a' + 12)) {
			cout << (char) (s[i] + 13);
		}
		else if (('0' <= s[i] && s[i] <= '9') || s[i] == ' ') {
			cout << s[i];
		}
		else {
			cout << (char) (s[i] - 13);
		}
	}cout << '\n';
	return 0;
}
