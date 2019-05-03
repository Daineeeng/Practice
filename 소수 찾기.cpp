#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int pCnt = 0;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		if (isPrime(n)) pCnt++;;
	}
	cout << pCnt << '\n';
	return 0;
}
