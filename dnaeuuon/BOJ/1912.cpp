#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	int max = -1001;
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += v[i];
		if (result > max) max = result;
		if (result < 0) result = 0;
	}
	cout << max;
}