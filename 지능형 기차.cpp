#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer = 0;
	int sum = 0;
	int in, out;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		sum -= out;
		sum += in;
		answer = max(answer, sum);
	}
	cout << answer << '\n';
	return 0;
}
