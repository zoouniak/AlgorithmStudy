#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++) { 
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int i, j;
	int left = 0, right = v.size() - 1;
	int result = 2000000001;

	while (left < right) {
		int diff = abs(v[left] + v[right]);
		if (diff == 0) {
			i = left;
			j = right;
			break;
		}
		if (result > diff) {
			result = diff;
			i = left;
			j = right;
		}
		else if (v[left] + v[right] < 0) left++;
		else if(v[left] + v[right] > 0) right--;
	}
	cout << v[i] << ' ' << v[j];
}