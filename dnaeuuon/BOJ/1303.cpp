#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[101][101];
int visited[101][101];
int result = 1;

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (!visited[nx][ny] && map[nx][ny] == map[x][y]) {
			dfs(nx, ny);
			result++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	int white = 0;
	int blue = 0;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			result = 1;
			if (!visited[i][j]) {
				dfs(i, j);
				if (map[i][j] == 'W') white += (int)pow(result, 2);
				else blue += (int)pow(result, 2);
			}
		}
	}
	cout << white << " " << blue;
}