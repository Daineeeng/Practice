#include <iostream>
#include <algorithm>
using namespace std;

struct egg {
	int S;
	int W;
	bool broken;
};
int N, ans = -1;
egg eggs[8];

void go(int now) {
	if (now == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (eggs[i].broken) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	if (eggs[now].broken) {
		go(now + 1);
		return;
	}
	else{
		bool done = false;

		for (int next = 0; next < N; next++) {
			// 겹치지 않는, 깨지지 않은 계란 찾기
			if (next == now || eggs[next].broken) continue;

			eggs[now].S -= eggs[next].W;
			eggs[next].S -= eggs[now].W;
			if (eggs[now].S <= 0) eggs[now].broken = 1;
			if (eggs[next].S <= 0) eggs[next].broken = 1;

			if (eggs[now].broken) go(now + 1);
			
			done = true;

			go(now + 1);

			eggs[now].S += eggs[next].W;
			eggs[next].S += eggs[now].W;
			if (eggs[now].S > 0) eggs[now].broken = 0;
			if (eggs[next].S > 0) eggs[next].broken = 0;
		}

		if (!done) go(now + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggs[i].S >> eggs[i].W;
		eggs[i].broken = 0;
	}

	go(0);
	cout << ans << '\n';
	return 0;
}
