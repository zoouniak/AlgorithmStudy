#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, input;
	cin >> N;
	int count = 0;
	int result = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++) {
		count++;
		if (count >= v.at(i)) {
			result++;
			count = 0;
		}
	}

	cout << result << endl;
}