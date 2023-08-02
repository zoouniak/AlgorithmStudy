#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[501];
int visited[501] = { 0, };


int dfs(int start, int depth) {
	visited[start] = true;
	if (depth >= 2) return 0;
	int cnt = 0;
	for (int i = 0; i < v[start].size(); i++) {
		int next_node = v[start][i];
		if (!visited[next_node]) {
			cnt += 1 + dfs(next_node, depth + 1);
		}
		else {
			cnt += dfs(next_node, depth + 1);
		}
	}
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	
	cout << dfs(1, 0) << endl;
}