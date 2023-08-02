#include <iostream>
#include <queue>
using namespace std;
int ice[1000][1000] = { 0, };
int visited[1000][1000] = { 0, };
int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	q.push(y);
	visited[x][y]++;
	if (!visited[x][y]) return false;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!ice[nx][ny] && !visited[nx][ny]) {
					q.push(nx);
					q.push(ny);
					visited[nx][ny]++;
				}
			}
		}
	}
}


int main() {
	int input;
	cin >> N >> M; // За, ї­

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			ice[i][j] = str[j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!ice[i][j] && !visited[i][j]) {
				//dfs(i, j);
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}