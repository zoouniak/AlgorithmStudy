#include <iostream>
#include <vector>
using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<long long> v; // 자료형 long long을 써야 오버플로우 ㄴㄴ
	long long max = 0;
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;
		v.push_back(input);
		if (max < input) max = input;
	}

	long long start = 1; // DivisionByZero
	long long end = max;

	long long result = 0;
	while (start <= end) {
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			sum += (v[i] / mid);
		}
		if (sum < K) end = mid - 1;
		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;
}