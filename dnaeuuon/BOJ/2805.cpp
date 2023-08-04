#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v;
	long long max = 0;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
		if (max < input) max = input;
	}
	long long start = 1;
	long long end = max;
	long long result = 0;

	while (start <= end) {
		long long sum = 0;
		long long middle = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if ((v[i] - middle) > 0) sum += (v[i] - middle);
		}
		if (sum < M) end = middle - 1;
		else {
			result = middle;
			start = middle + 1;
		}
	}
	cout << result;
}