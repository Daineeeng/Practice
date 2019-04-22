#include <iostream>
#include <math.h>
using namespace std;

int TC;
int score[1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed;
	cout.precision(3);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int Ns;
		cin >> Ns;
		int sumN = 0, cntN = 0;
		for (int i = 0; i < Ns; i++) {
			cin >> score[i];
			sumN += score[i];
		}
		double avg = (double) sumN / Ns;
		for (int i = 0; i < Ns; i++) {
			if (score[i] > avg) cntN++;
		}
		double per = (double)((cntN * 100.0) / Ns);
		double up_per = round(per * 1000) / 1000;
		cout << up_per << "%" << '\n';
	}
	return 0;
}
