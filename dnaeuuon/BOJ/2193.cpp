#include <iostream>
#include <vector>
using namespace std;
long long num[91][2];

int main() {
	int N;
	cin >> N;
	fill(&num[0][0], &num[N][1], 0);

	num[1][0] = 0; // 0의 개수
	num[1][1] = 1; // 1의 개수

	for (int i = 2; i <= N; i++) {
		if (num[i - 1][0]) {
			num[i][0] += num[i - 1][0];
			num[i][1] += num[i - 1][0];
		}
		if (num[i - 1][1]) {
			num[i][0] += num[i - 1][1];
		}
	}
	cout << num[N][0] + num[N][1];
}