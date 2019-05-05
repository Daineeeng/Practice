#include <iostream>
#include <algorithm>
using namespace std;

int M, N, ans = 987654321;
char graph[50][50];
char white[8][8]; char black[8][8];

void setting() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					black[i][j] = 'B';
					white[i][j] = 'W';
				}
				else {
					black[i][j] = 'W';
					white[i][j] = 'B';
				}
			}
			else {
				if (j % 2 == 0) {
					black[i][j] = 'W';
					white[i][j] = 'B';
				}
				else {
					black[i][j] = 'B';
					white[i][j] = 'W';
				}
			}
		}
	}
}

int makeWhite(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (graph[i][j] != white[i - x][j - y]) cnt++;
		}
	}
	return cnt;
}

int makeBlack(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (graph[i][j] != black[i - x][j - y]) cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	setting();
	for (int i = 0; i + 8 <= N; i++) {
		for (int j = 0; j + 8 <= M; j++) {
			ans = min(ans, min(makeWhite(i, j), makeBlack(i, j)));
		}
	}
	cout << ans << '\n';
	return 0;
}
