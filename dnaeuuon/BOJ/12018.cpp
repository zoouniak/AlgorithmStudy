#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> cnt;
	
	for (int i = 0; i < n; i++) {
		vector<int> v;
		int people, limit;
		cin >> people >> limit;
		for (int j = 0; j < people; j++) {
			int mileage;
			cin >> mileage;
			v.push_back(mileage);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		if (v.size() < limit) {
			cnt.push_back(1); // 최소 1이상 들어가야 됨!!
			v.clear();
			continue;
		}
		else {
			cnt.push_back(v[limit - 1]);
		}
		v.clear();
	}
	sort(cnt.begin(), cnt.end());

	int result = 0;
	for (int i = 0; i < cnt.size(); i++) {
		if (m - cnt[i] >= 0) {
			result++;
			m -= cnt[i];
		}
		else break;
	}

	cout << result;
}