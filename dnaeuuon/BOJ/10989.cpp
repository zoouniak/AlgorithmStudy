#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int cnt[10001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	map<int, int> num;
	int max = 0;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (max < input) max = input;
		if (!num.count(input)) num.insert(make_pair(input, 1));
		else num[input] += 1;
	}
	for (int i = 1; i <= max; i++) {
		if (num[i] != 0) {
			for (int j = 0; j < num[i]; j++) {
				cout << i << '\n';
			}
		}
	}
}