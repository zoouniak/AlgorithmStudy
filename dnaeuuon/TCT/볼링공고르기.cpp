#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int input;
	int arr[11] = { 0, };
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
		arr[input]++;
	}
	sort(v.begin(), v.end());

	long long result = (N * (N - 1)) / 2;
	for (int i = 1; i <= M; i++) {
		int count = arr[i];
		result -= (count * (count - 1)) / 2;
	}
	cout << result << endl;
}