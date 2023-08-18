#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[1001][1001];
queue<pair<int, int>> q;
int M, N;

void bfs(int x, int y) {
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
				q.push(make_pair(nx, ny));
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
			if (input == 1) q.push(make_pair(i, j));
		}
	}
	int x = q.front().first;
	int y = q.front().second;
	
	bfs(x, y);

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (map[i][j] > max) max = map[i][j];
		}
	}
	cout << max - 1;
}