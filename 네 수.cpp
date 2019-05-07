#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string A, B, C, D; cin >> A >> B >> C >> D;
	string s1 = A + B;
	string s2 = C + D;
	cout << stoll(s1) + stoll (s2) << '\n';
	return 0;
}
