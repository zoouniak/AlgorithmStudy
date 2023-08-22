#include <iostream>
#include <queue>
using namespace std;

int N;
char map[101][101];
int visited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0, -1, 1 };

void bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	visited[x][y] = true;

	while (!q.empty()) {
		int w = q.front();
		q.pop();
		int h = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = w + dx[i];
			int ny = h + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!visited[nx][ny]) {
				if (map[x][y] == map[nx][ny]) {
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;			
				}
			}
		}
	}
}

int main() {
	int falseCount = 0, trueCount = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				falseCount++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}
	fill(&visited[0][0], &visited[N][N], 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				trueCount++;
			}
		}
	}
	cout << falseCount << " " << trueCount;
}