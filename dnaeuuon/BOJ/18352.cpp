#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 1000000000;

vector<pair<int, int>> graph[300001];
int d[300001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
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
		graph[X].push_back(make_pair(Y, 1));
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