#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc, TC;
	long long ans, number;
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (tc = 1; tc <= TC; ++tc)
	{
		//init
		cin >> number;
		ans = 0;

		//solve
		bool go = true;
		if (number < 10) {
			ans = number;
			go = false;
		}

		long long sum = 0;
		while (go) {
			sum += number % 10;
			number /= 10;
			if (number == 0) {
				number = sum;
				if (number < 10) {
					ans = number;
					break;
				}
				else {
					sum = 0;
					continue;
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
