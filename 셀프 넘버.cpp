#include <iostream>
using namespace std;

bool notSelfNum[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i <= 10000; i++) {
		int dN = i;
		int temp = i;
		while (temp > 0) {
			dN += temp % 10;
			temp /= 10;
		}
		if (dN <= 10000) notSelfNum[dN] = true;
	}	
	for (int i = 1; i <= 10000; i++) {
		if (!notSelfNum[i]) cout << i << '\n';
	}
	return 0;
}
