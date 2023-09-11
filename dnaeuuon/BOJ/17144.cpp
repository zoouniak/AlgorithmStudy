#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[50][50];
int temp[50][50];
queue<pair<int, int>> q;
vector<pair<int, int>> air;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int r, c, t;

void Redirection() {
	while (!q.empty()) {
		int w = q.front().first;
		int h = q.front().second;
		q.pop();
		if (map[w][h] == -1) {
			temp[w][h] = -1;
			air.push_back(make_pair(w, h));
			continue;
		}
		int count = 0;
		for(int i = 0; i < 4; i++) {
			int nx = w + dx[i];
			int ny = h + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (map[nx][ny] == -1) continue;
			temp[nx][ny] += (map[w][h] / 5);
			count++;
		}
		temp[w][h] += map[w][h] - ((map[w][h] / 5) * count);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = temp[i][j];
		}
	}
	int w = air[0].first;
	int h = air[0].second;

	for (int i = 0; i < c - 1; i++) {
		map[0][i] = temp[0][i+1];
	}
	for (int i = w - 1; i > 0; i--) {
		map[i][0] = temp[i-1][0];
	}
	for (int i = c - 1; i > 0; i--) {
		map[w][i] = temp[w][i-1];
	}
	for (int i = 0; i < w; i++) {
		map[i][c-1] = temp[i+1][c-1];
	}
	map[w][1] = 0;
	
	w = air[1].first;
	h = air[1].second;

	for (int i = c - 1; i > 0; i--) {
		map[w][i] = temp[w][i - 1];
	}
	for (int i = w + 1; i < r - 1; i++) {
		map[i][0] = temp[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		map[r - 1][i] = temp[r - 1][i + 1];
	}
	for (int i = r - 1; i > w; i--) {
		map[i][c-1] = temp[i - 1][c - 1];
	}

	map[w][1] = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}
}

int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	for (int k = 0; k < t; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] != 0) q.push(make_pair(i, j));
			}
		}
		Redirection();
	}
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) result += map[i][j];
		}
	}
	cout << result;
}