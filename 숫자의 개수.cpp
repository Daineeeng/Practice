#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int cnt[10];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A, B, C; cin >> A >> B >> C;
	long long mtp = A * B * C;
	string mtps = to_string(mtp);
	for (int i = 0; i < mtps.length(); i++) {
		if (mtps[i] == '0') cnt[0]++;
		else if (mtps[i] == '1') cnt[1]++;
		else if (mtps[i] == '2') cnt[2]++;
		else if (mtps[i] == '3') cnt[3]++;
		else if (mtps[i] == '4') cnt[4]++;
		else if (mtps[i] == '5') cnt[5]++;
		else if (mtps[i] == '6') cnt[6]++;
		else if (mtps[i] == '7') cnt[7]++;
		else if (mtps[i] == '8') cnt[8]++;
		else cnt[9]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}
