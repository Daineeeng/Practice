#include <iostream>
#include <queue>
#include <string>
using namespace std;

char chess[8][8];
int timeLimit = 8;
queue<pair<int, int>> q;
//상.하.좌.우.좌상.좌하.우상.우하.그대로
int dx[] = { -1,1,0,0,-1,1,-1,1,0 };
int dy[] = { 0,0,-1,1,-1,-1,1,1,0 };


void bfs() {

	q.push({ 7,0 });

	while (timeLimit-- && !q.empty()) {
		int q_size = q.size();

		while (q_size--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			if (chess[cx][cy] == '#') {
				continue;
			}

			bool pass = true;
			for (int i = 0; i < 8; i++) {
				if (chess[i][cy] == '#') {
					pass = false;
					break;
				}
			}
			if (pass) {
				cout << 1 << '\n';
				exit(0);
			}

			for (int k = 0; k < 9; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && chess[nx][ny] == '.') {
					q.push({ nx,ny });
				}
			}
		}

		for (int i = 7; i > 0; i--) {
			for (int j = 0; j < 8; j++) {
				chess[i][j] = chess[i - 1][j];
			}
		}
		for (int i = 0; i < 8; i++) {
			chess[0][i] = '.';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess[i][j];
		}
	}

	bfs();

	if (!q.empty()) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0; 
}
