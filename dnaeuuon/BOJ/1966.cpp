#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<pair<int, int>> v;
		int m, n;
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			v.push_back(make_pair(input, j));
		}
		int count = 0;
		int cnt = 0;
		while (true) {
			bool priority = false;
			for (int j = 1; j < v.size(); j++) {
				if (v[0].first < v[j].first) {
					v.push_back(make_pair(v[0].first, v[0].second));
					v.erase(v.begin() + 0);
					priority = true;
					break;
				}
			}
			if (!priority) {
				if (v[0].second == n) {
					cout << cnt + 1<< '\n';
					break;
				}
				else cnt++;
				v.erase(v.begin() + 0);
			}
		}
	}
}