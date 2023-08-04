#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	int max = 0;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
		if (max < input) max = input;
	}
	int begin = 0;
	int end = max;
	int result = 0;

	while (begin <= end) {
		int sum = 0;
		int middle = (begin + end) / 2;
		for (int i = 0; i < N; i++) {
			if ((v[i] - middle) > 0) sum += (v[i] - middle);
		}
		if (sum < M) end = middle - 1;
		else {
			result = middle;
			begin = middle + 1;
		}
	}
	cout << result;
}