#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K, x, y, z, ans = 0;
// 상.하.좌.우.좌상.좌하.우상.우하
int dx[] = { -1,1,0,0,-1,1,-1,1 };
int dy[] = { 0,0,-1,1,-1,-1,1,1 };
int inputGraph[10][10];
int energyGraph[10][10];

struct tree {
	int x;
	int y;
	int z; //죽으면 -1
};
vector<tree> v;
vector<tree> dead;
vector<tree> mom;
queue<tree> q;

bool aging(tree t1, tree t2) {
	return t1.z < t2.z;
}

void simulation() {

	while (K--) {
		// spring :  나무가 자신의 나이만큼 자신이 있는 칸의 양분을 먹고, 나이가 1 증가한다. 한 칸에 여러 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
		int v_size = v.size();

		for (int i = 0; i<v.size(); i++) {
			int cx = v[i].x;
			int cy = v[i].y;
			int age = v[i].z;

			if (energyGraph[cx][cy] >= age) { // 양분 충분
				energyGraph[cx][cy] -= age;
				q.push({ cx,cy,age + 1 });

				if ((age + 1) % 5 == 0) {
					mom.push_back({ cx,cy,age + 1 });
				}
				else {
					continue;
				}
			}
			else if (energyGraph[cx][cy] < age) {  // 양분 부족, 양분을 먹지 못하고 즉시 죽는다.
				dead.push_back({ cx,cy,age });
			}
			else {
				continue;
			}
		}

		v.clear();
		while (!q.empty()) {
			v.push_back(q.front());
			q.pop();
		}

		// summer : 봄에 죽은 나무가 양분으로 변하게 된다.
		for (int i = 0; i<dead.size(); i++) {
			int cx = dead[i].x;
			int cy = dead[i].y;
			int age = dead[i].z;

			// 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
			int energy = age / 2;
			energyGraph[cx][cy] += energy;
		}
		dead.clear();

		// fall : 나이가 5의 배수인 나무가 인접한 8개의 칸에 나이가 1인 나무를 만든다. 땅을 벗어나는 칸에는 생기지 않는다.
		for (int i = 0; i<mom.size(); i++) {
			int cx = mom[i].x;
			int cy = mom[i].y;
			for (int k = 0; k < 8; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
				v.push_back({ nx, ny, 1 });
			}
		}
		mom.clear();

		// winter : 겨울에는 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				energyGraph[i][j] += inputGraph[i][j];
			}
		}
		sort(v.begin(), v.end(), aging);
	}
}

int getAns() {
	ans = v.size();
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> inputGraph[i][j];
			energyGraph[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		v.push_back({ x - 1,y - 1,z });
	}
	// 나무 나이 순 정렬
	sort(v.begin(), v.end(), aging);

	simulation();

	cout << getAns() << '\n';

	return 0;
}
