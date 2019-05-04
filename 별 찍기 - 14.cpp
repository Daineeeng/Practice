#include <iostream>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}
