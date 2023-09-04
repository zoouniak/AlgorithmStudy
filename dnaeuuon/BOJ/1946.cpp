#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int count = 0;
		vector<pair<int, int>> v;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		int start = v[0].second;
		for (int j = 0; j < n; j++) {
			if (start >= v[j].second) {
				count++;
				start = v[j].second;
			}
		}
		cout << count << '\n';
	}
}