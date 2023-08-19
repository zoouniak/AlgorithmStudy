#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> level;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		level.push_back(input);
	}
	int count = 0;
	for (int i = N - 1; i > 0; i--) {
		if (level[i] <= level[i - 1]) {
			int diff = (level[i - 1] - level[i]) + 1;
			count += diff;
			level[i - 1] -= diff;
		}
	}
	cout << count;
}