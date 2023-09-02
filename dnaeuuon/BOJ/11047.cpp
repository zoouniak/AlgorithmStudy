#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int result = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if ((k / v[i]) == 0) continue;
		else {
			result += k / v[i];
			k = k % v[i];
		}
	}
	cout << result;
}