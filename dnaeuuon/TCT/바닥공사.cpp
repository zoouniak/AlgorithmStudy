#include <iostream>
using namespace std;
int tile[1001];
int main() {
	int N;
	cin >> N;

	tile[1] = 1; // 2 * 1 타일 한 개
	tile[2] = 3; // 2 *2 타일

	for (int i = 3; i <= N; i++) {
		tile[i] += tile[i - 1] + tile[i - 2] * 2;
	}
	cout << tile[N] % 796796;
}