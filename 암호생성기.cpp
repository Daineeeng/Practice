#include <iostream>
#include <queue>
using namespace std;

int tc, TC, n;
queue<int> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	for (tc = 1; tc <= 10; tc++) {
		cin >> TC;
		
		for (int i = 0; i < 8; i++) {
			cin >> n;
			q.push(n);
		}

		int w = 1;
		while (!(q.back() == 0)) {
			int cx = q.front() - w;
			if (cx < 0) cx = 0;
			q.pop();
			q.push(cx);
			w++;
			if (w == 6) w = 1;
		}

		cout << '#' << TC << ' ';
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
	}
	return 0;
}
