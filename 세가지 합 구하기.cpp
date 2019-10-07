#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	long long tc, TC, s1, s2, s3, N;
	cin >> TC;
	for (tc = 1; tc <= TC; ++tc)
	{
		s1 = s2 = s3 = 0;
		cin >> N;

		s1 = N * (N + 1) / 2;
		s2 = N * N;
		s3 = N * (N + 1);

		cout << '#' << tc << ' ' << s1 << ' ' << s2 << ' ' << s3 << '\n';
	}
	return 0;
}
