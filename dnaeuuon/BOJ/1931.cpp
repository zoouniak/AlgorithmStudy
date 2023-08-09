#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	typedef pair<int, int> time;
	vector<time> v;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end());

	stack<time> s;
	s.push(v[0]);
	for (int i = 1; i < N; i++) {
		if (s.top().second > v[i].second) {
			s.pop();
			s.push(v[i]);
		}
		else if (s.top().second > v[i].first) {
			continue;
		}
		else {
			s.push(v[i]);
		}
	}
	cout << s.size();
}