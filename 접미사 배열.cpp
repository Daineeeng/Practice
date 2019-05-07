#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	string s; 
	cin >> s; 
	vector<string> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, s.length()));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
