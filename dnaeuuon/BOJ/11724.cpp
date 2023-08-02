#include <iostream>
#include <algorithm>
#include <vector> // dfs
#include <queue> // bfs
using namespace std;
vector<int> graph[1001];
int N, M;
int visited[1001] = { 0, };

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next_node = graph[v][i];
		if (!visited[next_node]) {
			dfs(next_node);
		}
	}
}
void bfs(int v) {
	queue<int> queue;
	queue.push(v);
	visited[v] = true;
	while (!queue.empty()) {
		for (int i = 0; i < graph[queue.front()].size(); i++) {
			int next_node = graph[queue.front()][i];
			if (!visited[next_node]) { 
				queue.push(next_node); 
				visited[next_node] = true;
			}
		}
		queue.pop();
	}
}
int main() {
	int u, v;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			count++;
		}
	}
	cout << count << endl;
}