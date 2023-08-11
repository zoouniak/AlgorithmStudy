#include <iostream>
using namespace std;
#define INF 1000000000
int map[101][101];

int main() {
	int N, M;
	cin >> N >> M;
	
	// fill(&map[1][1], &map[N][N], INF);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = INF;
		}
	} // 초기화
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) map[i][j] = 0; // 자기 자신에게 가는 길
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	int X, K;
	cin >> X >> K;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	int result = map[1][K] + map[K][X];

	if (result >= INF) cout << -1;
	else cout << result;
}