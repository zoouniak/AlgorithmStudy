#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	vector<long long> cost;
	vector<long long> oil;

	for (int i = 0; i < N - 1; i++) {
		long long input;
		cin >> input;
		cost.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;
		oil.push_back(input);
	}

	long long min = oil[0];
	long long result = 0;
	for (int i = 0; i < N - 1; i++) {
		if (min > oil[i]) min = oil[i];
		result += cost[i] * min;
	}
	
	cout << result;
}