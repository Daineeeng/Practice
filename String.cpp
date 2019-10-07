#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);

	int tc, TC, ans;
	string f, s;
	for (tc = 1; tc <= 10; ++tc)
	{
		cin >> TC;
		cin >> f;
		cin >> s;
		ans = 0;

		int flen = f.length();
		int slen = s.length();

		for (int i = 0; i <= slen - flen; i++) {
			string tmp = "";
			for (int j = i; j < i + flen; j++) {
				tmp += s[j];
				if (tmp == f) ans++;
			}
		}

		cout << '#' << TC << ' ' << ans << '\n';
	}
	return 0;
}
