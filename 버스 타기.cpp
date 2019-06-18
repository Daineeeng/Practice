#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	int TC;	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int N, K;
		cin >> N >> K;
		vector<int> v;

		for (int i = 0; i < N; i++) {
			int cpt;
			cin >> cpt;
			v.push_back(cpt);
		}
		
		int Answer = 1;
		sort(v.begin(), v.end());
		int vsize = v.size();
		for (int i = 1; i < vsize; i++) {
			if (v[i] - v[i - Answer] <= K) {
				Answer++;
			}
		}
		cout << "Case #" << tc << '\n' << Answer << '\n';
	}
	return 0;
}
