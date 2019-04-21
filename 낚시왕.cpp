#include <iostream>
#include <memory.h>
using namespace std;

int R, C, M, getCnt;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
struct shark {
	int s, d, z;
}; 
shark graph[100][100];
shark temp[100][100];

void sharkMove() {
	memset(temp, 0, sizeof(temp));
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (graph[x][y].z) {
				int d = graph[x][y].d;
				if (graph[x][y].d < 2) { // 상하
					int ns = graph[x][y].s % ((R - 1) * 2);
					int nx = x;
					while (ns--) {
						if (nx == 0 && d == 0) d = 1;
						if (nx == R-1 && d == 1) d = 0;
						nx += dx[d];
					}
					if (graph[x][y].z > temp[nx][y].z) temp[nx][y] = { graph[x][y].s,d,graph[x][y].z };
				}
				else { // 우좌
					int ns = graph[x][y].s % ((C - 1) * 2);
					int ny = y;
					while (ns--) {
						if (ny == 0 && d == 3) d = 2;
						if (ny == C - 1 && d == 2) d = 3;
						ny += dy[d];
					}
					if (graph[x][y].z > temp[x][ny].z) temp[x][ny] = { graph[x][y].s,d,graph[x][y].z };
				}
				graph[x][y] = { 0,0,0 };
			}
		}
	}
	memcpy(graph, temp, sizeof(graph));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		graph[r - 1][c - 1] = { s,d - 1,z };
	}
	for (int kc = 0; kc < C; kc++) {
		for (int kr = 0; kr < R; kr++) {
			if (graph[kr][kc].z) {
				getCnt += graph[kr][kc].z;
				graph[kr][kc] = { 0,0,0 };
				break;
			}
		}
		sharkMove();
	}
	cout << getCnt << '\n';
	return 0;
}
