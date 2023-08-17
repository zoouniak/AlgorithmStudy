#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[101];
int visited[101];
int cnt = 0;
int N;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (int j = 0; j < v[i].size(); j++) {
			int next_node = v[i][j];
			if (!visited[next_node]) {
				q.push(next_node);
				visited[next_node] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}

int main() {
	int K;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	bfs(1);
}