#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<string> v;
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		int min = 1000001;
		for (int j = 0; j < m - 2; j++) {
			for (int k = j + 1; k < m - 1; k++) {
				for (int n = k + 1; n < m; n++) {
					int cnt = 0;
					for (int h = 0; h < 4; h++) {
						if (v[j][h] != v[k][h]) cnt++;
						if (v[n][h] != v[k][h]) cnt++;
						if (v[j][h] != v[n][h]) cnt++;
					}
					if (min > cnt) min = cnt;
					if (min == 0) break;
				}
				if (min == 0) break;
			}
			if (min == 0) break;
		}
		cout << min << '\n';
	}
}