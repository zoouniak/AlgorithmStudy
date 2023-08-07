#include <iostream>
using namespace std;
int memo[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	for (int i = 4; i <= 11; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
	}

	for (int i = 0; i < T; i++) {
		int input;
		cin >> input;
		cout << memo[input] << '\n';
	}
}