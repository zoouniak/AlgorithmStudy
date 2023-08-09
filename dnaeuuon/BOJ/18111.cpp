#include <iostream>
using namespace std;
int map[500][500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, B;
	int input;
	cin >> N >> M >> B;
	int max = 0;
	int min = 257;
	int time = 1000000000;
	int height = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i][j] = input;
			if (max < input) max = input;
			if (min > input) min = input;
		}
	}

	for (int i = min; i <= max; i++) {
		int count = 0;
		int block = 0; // 필요한 블록수
		int plusBlock = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (map[x][y] > i) { // 제거한다 (+2)
					plusBlock += map[x][y] - i; // 뺀 블록 수만큼 더해주기
					count += 2 * (map[x][y] - i); // 뺀 만큼 시간
				}
				else if (map[x][y] < i) {
					block += i - map[x][y]; // 쌓아야 할 블록 수
					count += i - map[x][y]; // 쌓은 만큼 시간
				}
			}
		}
		if (B + plusBlock >= block) {
			if (count < time) {
				time = count;
				height = i;
			}
			else if (count == time) {
				height = i;
			}
		}
	}
	cout << time << " " << height;
}