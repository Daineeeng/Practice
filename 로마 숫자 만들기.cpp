#include <iostream>
#include <set>
using namespace std;

int N, temp;
set<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//reopen("input.txt", "r", stdin);
	cin >> N;
	for (int a = 0; a <= N; a++) {
		for (int b = 0; b <= N; b++) {
			for (int c = 0; c <= N; c++) {
				for (int d = 0; d <= N; d++) {
					if (a + b + c + d == N) {
						temp = a * 1 + b * 5 + c * 10 + d * 50;
						s.insert(temp);
					}
				}
			}
		}
	}
	cout << s.size() << '\n';
	return 0;
}
