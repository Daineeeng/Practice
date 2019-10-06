#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;

int TC, number, trial, len, ans;
string str_num;
bool visited[1000000][6];

void dfs(int N) {
	// 종료조건
	int tmp = stoi(str_num);
	if (visited[tmp][N] == true) return;
	visited[tmp][N] = true;
	if (N == 0) {
		if (ans < tmp)
			ans = tmp;
		return;
	}
	// 반복문
	for (int i = 0; i < len-1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			swap<char>(str_num[i], str_num[j]);
			dfs(N - 1);
			swap<char>(str_num[i], str_num[j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> number;
		cin >> trial;
		memset(visited, 0, sizeof(visited));
		str_num = to_string(number);
		len = str_num.length();
		ans = 0;
		if (trial > 5) {
			if (trial % 2 == 1)
				trial = 5;
			else
				trial = 4;
		}
		dfs(trial);
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
