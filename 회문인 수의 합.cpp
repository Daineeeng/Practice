#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Answer, pvsize;
vector<int> pv;

bool palindrome(int n) {
	string str = to_string(n);
	int strlen = str.length();
	for (int i = 0; i < strlen; i++) {
		if (str[i] != str[strlen - i - 1]) {
			return false;
		}
	}
	return true;
}

bool one(int n) {
	for (int i = 0; i < pvsize; i++) {
		if (pv[i] == n) {
			cout << 1 << ' ' << pv[i] << '\n';
			return true;
		}
	}
	return false;
}

bool two(int n) {
	for (int i = 0; i < pvsize; i++) {
		for (int j = 0; j < pvsize; j++) {
			if (pv[i] + pv[j] == n) {
				cout << 2 << ' ' << pv[j] << ' ' << pv[i] << '\n';
				return true;
			}
		}
	}
	return false;
}

bool three(int n) {
	for (int i = 0; i < pvsize; i++) {
		for (int j = 0; j < pvsize; j++) {
			for (int k = 0; k < pvsize; k++) {
				if (pv[i] + pv[j] + pv[k] == n) {
					cout << 3 << ' ' << pv[k] << ' ' << pv[j] << ' ' << pv[i] << '\n';
					return true;
				}
			}
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	//freopen("Input.txt", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 0; i <= 10000; i++) {
		if (palindrome(i)) pv.push_back(i);
	}
	pvsize = pv.size();

	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{	
		int N; cin >> N;
		cout << "Case #" << tc << '\n';
		if (!one(N) && !two(N) && !three(N)) {
			cout << 0 << '\n';
		}
	}

	return 0;
}
