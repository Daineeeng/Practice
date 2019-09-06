#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	long long A, B;
	int ans = 0;
	cin >> A >> B;
	
	while (true) {
		if (A == B) {
			ans++;
			break;
		}
		else if (A > B) {
			ans = -1;
			break;
		}
		else if (B % 10 == 1) {
			B /= 10;
			ans++;
		}
		else if (B % 2 == 0) {
			B /= 2;
			ans++;
		}
		else {
			ans = -1;
			break;
		}
	}

	cout << ans << '\n';
	return 0;
}
