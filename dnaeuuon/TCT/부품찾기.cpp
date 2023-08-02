#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stock;

void binarySearch(int n) {
	int begin = 0;
	int end = stock.size() - 1;
	
	while (begin <= end) {
		int middle = (begin + end) / 2;
		if (stock[middle] == n) {
			cout << "yes" << '\n';
			return;
		}
		else if (n < stock[middle]) {
			end = middle - 1;
		}
		else { // n > middle
			begin = middle + 1;
		}
	}
	cout << "no" << '\n';
}

int main() {
	int N;
	int M;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		stock.push_back(input);
	}
	sort(stock.begin(), stock.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		binarySearch(input);
	}
}