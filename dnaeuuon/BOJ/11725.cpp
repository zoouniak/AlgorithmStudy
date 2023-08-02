#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[100001];
int visited[100001];
int arr[100001];

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next_node = graph[v][i];
		if (!visited[next_node]) {
			arr[next_node] = v;
			dfs(next_node);
		}
	}
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v];
	while (!q.empty()) {
		for (int i = 0; i < graph[q.front()].size(); i++) {
			int next_node = graph[q.front()][i];
			if (!visited[next_node]) {
				arr[next_node] = q.front();
				q.push(next_node);
				visited[next_node] = true;
			}
		}
		q.pop();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	// dfs(1);
	bfs(1);
	for (int i = 2; i <= N; i++) {
		cout << arr[i] << '\n';
	}
}