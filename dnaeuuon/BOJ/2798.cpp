#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int max = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				result = v[i] + v[j] + v[k];
				if (result > M) result = 0;
				else {
					if (result > max) max = result;
				}
			}
		}
	}
	cout << max;
}