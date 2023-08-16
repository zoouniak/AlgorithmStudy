#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[101][101];
int N, M;

void bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	q.push(b);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	cout << map[N - 1][M - 1];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	bfs(0, 0);
}