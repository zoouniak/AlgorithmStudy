#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[501][501];
int visited[501][501];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	
	while (!q.empty()) {
		int w = q.front().first;
		int h = q.front().second;
		visited[w][h] = 1;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = w + dx[i];
			int ny = h + dy[i];
			if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
			if (!visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				map[nx][ny] = map[w][h] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int x, y;
	cin >> x >> y;
	vector<pair<int, int>> v;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		v.push_back(make_pair(a, b));
	}
	bfs(x, y);
	for (int i = 0; i < M; i++) {
		int a = v[i].first;
		int b = v[i].second;
		cout << map[a][b] << " ";
	}
}