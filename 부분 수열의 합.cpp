#include <iostream>
#include <memory.h>
#define MAXN 20
using namespace std;

int TC, N, K, ans;
int num[MAXN];

void dfs(int sum, int idx, int nsize) {
	if (sum == K && nsize >= 1) {
		ans++;
		return;
	}
	if (idx >= N) return;

	dfs(sum + num[idx], idx + 1, nsize + 1);
	dfs(sum, idx + 1, nsize);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc)
	{
		//init
		cin >> N >> K;
		memset(num, 0, sizeof(num));
		ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		//solve
		dfs(0, 0, 1);
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
