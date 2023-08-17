#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[1001][1001];
int visited[1001][1001];
int M, N;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 0) {
				map[nx][ny] = map[x][y] + 1;
				if (!visited[nx][ny]) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
			else if (map[nx][ny] > 1 && map[nx][ny] > map[x][y]) {
				map[nx][ny] = map[x][y] + 1;
				if (!visited[nx][ny]) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				fill(&visited[0][0], &visited[N - 1][M - 1], 0);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return -1;
			}
			if (map[i][j] > max) max = map[i][j];
		}
	}
	cout << max - 1;
}