#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << v.at(i) << " ";
	}
}