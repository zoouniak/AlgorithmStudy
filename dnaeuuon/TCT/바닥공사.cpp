#include <iostream>
using namespace std;
int tile[1001];
int main() {
	int N;
	cin >> N;

	tile[1] = 1; // 2 * 1 Ÿ�� �� ��
	tile[2] = 3; // 2 *2 Ÿ��

	for (int i = 3; i <= N; i++) {
		tile[i] += tile[i - 1] + tile[i - 2] * 2;
	}
	cout << tile[N] % 796796;
}