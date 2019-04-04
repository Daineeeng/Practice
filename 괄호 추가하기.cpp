#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, ans;
string S;
queue<pair<int, int>> q;

int oper(int a, int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else return a * b;
}


int bfs() {
	ans = -0x7fffffff;
	if (N == 1) {
		return (S[0] - '0');
	}
	q.push({ 2, S[0] - '0' });
	while (!q.empty()) {
		int i = q.front().first;
		int subSum = q.front().second;
		q.pop();

		if (i > N) {
			ans = max(ans, subSum);
			continue;
		}

		if (i < N - 2) {
			q.push({ i + 4, oper(subSum, oper(S[i] - '0', S[i + 2] - '0', S[i + 1]), S[i - 1]) });
		}
		q.push({ i + 2, oper(subSum, S[i] - '0', S[i - 1]) });
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> S;

	cout << bfs() << '\n';
	return 0;
}
