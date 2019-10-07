#include<iostream>
using namespace std;

int recursion(int N, int M) {
	if (M == 0) return 1;
	else if(M == 1) return N;
	return N * recursion(N, M - 1);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	int tc, TC, ans, N, M;
	for (tc = 1; tc <= 10; ++tc)
	{
		cin >> TC;
		cin >> N >> M;
		ans = recursion(N, M);

		cout << '#' << TC << ' ' << ans << '\n';
	}
	return 0;
}
