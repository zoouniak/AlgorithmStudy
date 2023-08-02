#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> v;
	int input;
	int continuous = K;
	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < M; i++) {
		if (continuous > 0) {
			result += v.at(0);
			continuous--;
		}
		else {
			result += v.at(1);
			continuous = K;
		}
	}
	cout << result << endl;
}