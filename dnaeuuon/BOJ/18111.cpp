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
		int block = 0; // �ʿ��� ��ϼ�
		int plusBlock = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (map[x][y] > i) { // �����Ѵ� (+2)
					plusBlock += map[x][y] - i; // �� ��� ����ŭ �����ֱ�
					count += 2 * (map[x][y] - i); // �� ��ŭ �ð�
				}
				else if (map[x][y] < i) {
					block += i - map[x][y]; // �׾ƾ� �� ��� ��
					count += i - map[x][y]; // ���� ��ŭ �ð�
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