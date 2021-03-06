#include <iostream>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int A, B; cin >> A >> B;
	cout << gcd(A, B) << '\n';
	cout << lcm(A, B) << '\n';		
	return 0;
}
