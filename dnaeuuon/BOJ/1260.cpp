#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dfs_visited[10001];
int bfs_visted[10001];
vector<int> map[10001];

void dfs(int v) { // stack
	dfs_visited[v] = true;
	cout << v << " ";

	for (int i = 0; i < map[v].size(); i++) {
		int next_node = map[v][i];
		if (!dfs_visited[next_node]) {
			dfs(next_node);
		}
	}
}
void bfs(int v) {
	queue<int> queue;
	queue.push(v);
	bfs_visted[v] = true;
	while (!queue.empty()) {
		for (int i = 0; i < map[queue.front()].size(); i++) {
			int next_node = map[queue.front()][i];
			if (!bfs_visted[next_node]) {
				queue.push(next_node);
				bfs_visted[next_node] = true; // 문제점 1
			}
		}
		cout << queue.front() << " ";
		queue.pop();
	}
}

int main() {
	int n, m, v;
	int node1, node2;
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		map[node1].push_back(node2);
		map[node2].push_back(node1); // 문제점 2
	}
	for (int i = 1; i <= m; i++) {
		sort(map[i].begin(), map[i].end()); // 문제점 3
	}

	dfs(v);
	cout << endl;
	bfs(v);
}