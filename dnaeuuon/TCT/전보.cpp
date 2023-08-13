#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF = 1000000000;

vector<pair<int, int>> map[30001];
int d[30001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < map[current].size(); i++) {
			int next = map[current][i].first;
			int nextDistance = distance + map[current][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {
	int N, M, C;
	cin >> N >> M >> C;

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 1; i <= M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		map[X].push_back(make_pair(Y, Z));
	}
	dijkstra(C);
	int max = 0;
	int cnt = -1; // 시작 노드 제외
	for (int i = 1; i <= N; i++) {
		if (d[i] == INF) continue;
		if (max < d[i]) max = d[i];
		cnt++;
	}
	cout << cnt << " " << max;
}