#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int X, Y;
int sheep, wolf;
char map[250][250];
int visited[250][250];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= X || ny >= Y) continue;
		if (!visited[nx][ny] && map[nx][ny] != '#') { // 울타기 안 확인
			if (map[nx][ny] == 'k') sheep++;
			else if (map[nx][ny] == 'v') wolf++;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> X >> Y;
	for (int i = 0; i < X; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < Y; j++) {
			map[i][j] = str[j];
		}
	}
	int S = 0, W = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (!visited[i][j] && map[i][j] == '#') { // 울타리 기준으로 세기
				sheep = 0;
				wolf = 0;
				dfs(i, j);
				if (sheep > wolf) S += sheep;
				else W += wolf;
			}
		}

	}
	cout << S << " " << W;
}