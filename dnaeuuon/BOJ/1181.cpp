#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int compare(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	typedef pair<int, string> word;
	vector<word> v;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(make_pair(str.length(), str));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << '\n'; // �߿�!!!!
	} 
}