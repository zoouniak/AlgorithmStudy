#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		b.push_back(input);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < K; i++) {
		if (a.at(i) < b.at(b.size() - 1 - i)) a.at(i) = b.at(b.size() - 1 - i);
			// swap(a.at(i), b.at(b.size() - i - 1)); 
			// a 배열의 합이므로 굳이 swap할 필요도 없음!!
		else break;
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += a.at(i);
	}
	cout << result << endl;
}