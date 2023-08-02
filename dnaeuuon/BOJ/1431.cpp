#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	typedef pair<int, pair<int, string>> word;
	vector<word> v;
	for (int i = 0; i < N; i++) {
		int count = 0;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (isdigit((char)str[j])) count += str[j] - '0';
		}
		v.push_back(make_pair(str.length(), make_pair(count, str)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second.second << '\n';
	}
}