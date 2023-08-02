#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int dw[8] = { -1,-1,-1,0,0,1,1,1 };
int dh[8] = { -1,0,1,-1,1,-1,0,1 };
int map[50][50];
int visited[50][50];
int w, h;

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dh[i]; // 행(세로)
		int ny = y + dw[i]; // 열(가로)
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (!visited[nx][ny] && map[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	while (true) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int input;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> input;
				map[i][j] = input;
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) {
					dfs(i, j);
					cnt++;
				}

			}
		}
		cout << cnt << endl;
	}
}