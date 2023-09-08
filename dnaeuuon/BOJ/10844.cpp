#include <iostream>
using namespace std;
long long dp[101][10];

int main() {
	int n;
	cin >> n;

	dp[1][0] = 0; // 0으로 시작할 수 없음
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % 1000000000; // 0으로 끝나면 1만 올 수 있음
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000; // 9로 끝나면 8만 올 수 있음
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] % 1000000000) + (dp[i - 1][j - 1] % 1000000000);
			}
		}
	}

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n][i];
		result %= 1000000000;
		// result += (dp[n][i] % 1000000000) 하면 틀린다... 연산자 우선순위??	
	}

	cout << result;
}