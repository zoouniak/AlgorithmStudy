#include <iostream>
#include <queue>
using namespace std;
int map[200][200] = { 0, };
int visited[200][200] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M; // Çàx ¿­y
int cnt = 0;

void bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		visited[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (!map[nx][ny]) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	cout << map[N - 1][M - 1] << endl;
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