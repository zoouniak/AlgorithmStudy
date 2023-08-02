#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> v[501];
int visited[501];

void bfs(int start) {
	int count = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;

	for (int i = 0; i < v[q.front()].size(); i++) {
		int next_node = v[q.front()][i];
		if (!visited[next_node]) {
			q.push(next_node);
			visited[next_node] = true;
			count++;
		}
	}
	q.pop();

	while (!q.empty()) {
		for (int i = 0; i < v[q.front()].size(); i++) {
			int next_node = v[q.front()][i];
			if (!visited[next_node]) {
				visited[next_node] = true;
				count++;
			}
		}
		q.pop();
	}

	cout << count;
}
int main() {
	cin >> N >> M;
	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
}