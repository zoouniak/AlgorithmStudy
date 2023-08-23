#include <iostream>
#include <queue>
using namespace std;
int M, N, H;
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };
int map[101][101][101];
queue<pair<int, pair<int, int>>> q;

void bfs() {
	while (!q.empty()) {
		int h = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nh = h + dh[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N || nh < 0 || nh >= H) continue;
			if (map[nh][nx][ny] == 0) {
				map[nh][nx][ny] = map[h][x][y] + 1;
				q.push(make_pair(nh, make_pair(nx, ny)));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				int input;
				cin >> input;
				map[h][x][y] = input;
				if (map[h][x][y] == 1) q.push(make_pair(h, make_pair(x, y)));
			}
		}
	}
	bfs();
	int max = 0;

	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[h][x][y] == 0) {
					cout << -1;
					return 0;
				}
				if (max < map[h][x][y]) max = map[h][x][y];
			}
		}
	}

	cout << max - 1;
}