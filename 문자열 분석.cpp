#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 100; i++) {
		string s;
	    getline(cin, s);
		int slen = s.length();
		if (slen == 0) break;

		int lower = 0; int upper = 0; int num = 0; int space = 0;
		for (int j = 0; j < slen; j++) {
			if ('A' <= s[j] && s[j] <= 'Z') {
				upper++;
			}
			else if ('a' <= s[j] && s[j] <= 'z') {
				lower++;
			}
			else if ('0' <= s[j] && s[j] <= '9') {
				num++;
			}
			else space++;
		}
		cout << lower << " " << upper << " " << num << " " << space << '\n';
	}
	return 0;
}
