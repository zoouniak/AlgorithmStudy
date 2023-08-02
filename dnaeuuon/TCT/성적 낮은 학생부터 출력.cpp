#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}
int main() {
	vector<pair<string, int>> student;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int score;
		cin >> name >> score;
		student.push_back(make_pair(name, score));
	}
	sort(student.begin(), student.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << student[i].first << " ";
	}
}