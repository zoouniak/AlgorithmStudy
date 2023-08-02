#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*void dfs(int row, int col, int** visited, int* map) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < map[v].size(); i++) {
		int next_node = map[v][i];
		if (!visited[next_node]) {
			dfs(next_node, visited);
		}
	}
}*/
int main() {
	int T;
	int M, N, K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		int map[51][51] = { 0, };
		int visited[51][51] = { 0, }; // ї­ За
		for (int j = 0; j < K; j++) {
			int row, col;
			cin >> col >> row;
			map[row][col] = 1;
		}
		int cnt = 0;
		for (int j = 0; i < N; j++) {
			for (int k = 0; k < M; k++) {
				if (!visited[j][k]) {
					visited[j][k] = 1;
					//dfs(j, k + 1, visited, map);
					//dfs(j + 1, k, visited, map);
					if (map[j][k + 1] == 1 && visited[j][k + 1] == 0) visited[j][k + 1] = 1;
					if (map[j + 1][k] == 1 && visited[j + 1][k] == 0) visited[j + 1][k] = 1;
				}
				else cnt++;
			}
		}
		cout << cnt << endl;
	}
}