#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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

	sort(v.begin(), v.end());

	int size = round(v.size() * 0.15);
	double result = 0;
	double count = 0;

	for (int i = size; i < v.size() - size; i++) {
		result += v[i];
		count++;
	}
	result /= count;
	result = round(result);

	if (n == 0) cout << 0;
	else cout << result;
}