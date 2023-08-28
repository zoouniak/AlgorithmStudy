#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int visited[1001][1001];
int dw[4] = { 0,0,1,-1 };
int dh[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	map[x][y] = 0;

	while (!q.empty()) {
		int w = q.front();
		q.pop();
		int h = q.front();
		q.pop();
		visited[w][h] = true;
		for (int i = 0; i < 4; i++) {
			int nw = w + dw[i];
			int nh = h + dh[i];
			if (!visited[nw][nh] && map[nw][nh] == 1) {
				map[nw][nh] = map[w][h] + 1;
				q.push(nw);
				q.push(nh);
				visited[nw][nh] = true;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}
	bfs(x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !visited[i][j]) map[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}