#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 1000000000;

vector<int> graph[300001];
int d[300001];

void dijkstra(int start) {
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (d[next] == INF) {
				d[next] = d[current] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		graph[X].push_back(Y);
	}

	dijkstra(X);
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			cout << i << '\n';
			cnt++;
		}
	}
	if (cnt == 0) cout << -1;
}