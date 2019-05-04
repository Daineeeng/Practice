#include <iostream>
using namespace std;
int students[5], sum;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> students[i];
		if (students[i] < 40) students[i] = 40;
		sum += students[i];
	}
	cout << sum / 5 << '\n';
	return 0;
}
