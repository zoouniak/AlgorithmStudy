#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> m;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m.insert(make_pair(str, 1));
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (m.count(str)) m[str] += 1;
	}

	vector<string> v;
	for (const auto& kv : m) {
		if (kv.second != 1) v.push_back(kv.first);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}