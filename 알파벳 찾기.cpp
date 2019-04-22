#include <iostream>
#include <string>
#include<memory.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int alpha[26];
	memset(alpha, -1, sizeof(alpha));
	string S; cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (alpha[S[i] - 'a'] == -1) alpha[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << ' ';
	}
	cout << '\n';
	return 0;
}
