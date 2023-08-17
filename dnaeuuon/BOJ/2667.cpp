#include <iostream>
#include <queue>
#include <vector>;
#include <algorithm>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[25][25];
int visited[25][25];
vector<int> cnt;
int N;

void bfs(int x, int y) {
	queue<int> q;
	int count = 0;
	q.push(x);
	q.push(y);
	visited[x][y] = 1;
	count++;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!visited[nx][ny] && map[nx][ny] == 1) {
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = 1;
				count++;
			}
		}
	}
	cnt.push_back(count);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				bfs(i, j);
				total++;
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << total << '\n';
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}
}