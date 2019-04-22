#include <iostream>
#include <string>
using namespace std;
int TC;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int R; cin >> R;
		string S; cin >> S;
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < R; j++) cout << S[i];
		}
		cout << '\n';
	}
	return 0;
}
