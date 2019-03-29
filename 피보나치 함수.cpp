#include <stdio.h>
using namespace std;

int TC, N, dp[41];

int fibonacci(int N) {
	if (N <= 0) {
		dp[0] = 0;
		return 0;
	} else if (N == 1) {
		dp[1] = 1;
		return 1;
	}
	if (dp[N] != 0) {
		return dp[N];
	}
	else {
		return dp[N] = fibonacci(N - 1) + fibonacci(N - 2);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d",&TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		
		if (N == 0) {
			printf("%d %d\n", 1, 0);
		}
		else if (N == 1) {
			printf("%d %d\n", 0, 1);
		}
		else {
			fibonacci(N);
			printf("%d %d\n", dp[N - 1], dp[N]);
		}
	}
	return 0;
}
