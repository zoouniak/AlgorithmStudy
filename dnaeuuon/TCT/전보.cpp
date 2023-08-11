#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
int N, M, C;
int map[100][100];
int visited[30001] = { 0, };
int dist[30001];
int min_node;

int getSmallNode() {
	int min = INF;
	int minIndex = 0;

	for (int i = 1; i <= N; i++) {
		if (dist[i] < min && !visited[i]) {
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = map[start][i];
	}
	visited[start] = true;
	for (int i = 1; i < N; i++) {
		min_node = getSmallNode();
		visited[min_node] = true;
		for (int j = 1; j <= N; j++) {
			if (!visited[j])
				if (dist[min_node] + map[min_node][j] < dist[j]) {
					dist[j] = dist[min_node] + map[min_node][j];
				}
		}
	}
}

int main() {
	int cnt = 0;
	cin >> N >> M >> C;
	fill(&map[1][1], &map[N][N], INF);
	fill(&dist[0], &dist[N], INF);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) map[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		map[X][Y] = Z;
	}

	dijkstra(C);
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < dist[i]) max = dist[i];
		if (dist[i] != INF) cnt++;
	}
	cout << cnt << " " << max;
}