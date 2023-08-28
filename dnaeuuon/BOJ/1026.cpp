#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		B.push_back(input);
	}
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += A[i] * B[i];
	}
	cout << result;
}