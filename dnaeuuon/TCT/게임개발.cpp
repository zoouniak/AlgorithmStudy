#include <iostream>
using namespace std;
int map[50][50];

int main() {
	int row, col;
	cin >> row >> col;
	int x, y, direction;
	cin >> x >> y >> direction;

	int count = 0;
	int visitCnt = 0;
	int dir[4][2] = { {0,-1},{-1,0},{0,1}, {1,0} };
	int backDir[4][2] = { {1,0}, {0,-1},{-1,0},{0,1} };
	// 0: ��, 1: ��, 2: ��, 3: ��
	// 1: �ٴ�, 0: ����

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	map[x][y] = 2;
	int currentX = x;
	int currentY = y;
	while (true) {
		if (visitCnt == 4) {
			x = x + backDir[direction][0];
			y = y + backDir[direction][1];
			if (map[x][y] == 1) break;
			else {
				count++;
				visitCnt = 0;
				currentX = x;
				currentY = y;
				continue;
			}
		}
		// ���� ���� �̵�
		x = x + dir[direction][0];
		y = y + dir[direction][1];

		if (map[x][y] == 0) {
			// ���� ������ ���� ĭ
			map[x][y] = 2;
			count++;
			visitCnt = 0;
			direction = (direction + 3) % 4;
			currentX = x;
			currentY = y;
			continue;
	
		}
		// �̹� ���� ĭ || �ٴ�
		visitCnt++;
		direction = (direction + 3) % 4;
		x = currentX;
		y = currentY;
	}
	cout << count << endl;
}
