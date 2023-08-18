#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 1000000000;

vector<pair<int, int>> graph[20001];
int visited[20001];
int d[20001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second; // pq에는 second에 node
		int distance = -pq.top().first;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first; // 그래프에는 first에 node
			int nextDistance = distance + graph[current][i].second; 

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	for (int i = 1; i <= E; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
	}
	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}