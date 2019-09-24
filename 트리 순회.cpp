#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<pair<char, char>> v[26];

void preOrder(char root) {
	char left = v[root - 'A'].front().first;
	char right = v[root - 'A'].front().second;

	cout << root;
	if (left != '.') preOrder(left);
	if (right != '.') preOrder(right);
}

void inOrder(char root) {
	char left = v[root - 'A'].front().first;
	char right = v[root - 'A'].front().second;

	if (left != '.') inOrder(left);
	cout << root;
	if (right != '.') inOrder(right);
}

void postOrder(char root) {
	char left = v[root - 'A'].front().first;
	char right = v[root - 'A'].front().second;

	if (left != '.') postOrder(left);
	if (right != '.') postOrder(right);
	cout << root;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		v[a - 'A'].push_back({ b, c });
	}

	preOrder('A'); cout << '\n';
	inOrder('A'); cout << '\n';
	postOrder('A'); cout << '\n';
	return 0;
}
