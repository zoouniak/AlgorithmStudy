#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int money[1000001];

void count(vector<int> coin, vector<bool> visited, int n) {
	int cnt = n;
	for (int j = 0; j < coin.size() - cnt; j++) {
		visited[j] = false;
	}
	do {
		int sum = 0;
		for (int j = 0; j < coin.size(); j++) {
			if (visited[j]) sum += coin[j];
		}
		money[sum] = 1;
	} while (next_permutation(visited.begin(), visited.end()));
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> coin;
	vector<bool> visited(N, true);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		coin.push_back(input);
	}

	for (int i = 1; i <= N; i++) {
		count(coin, visited, i);
	}
	int index = 1;
	while (true) {
		if (money[index] != 1) {
			cout << index << '\n';
			break;
		}
		else index++;
	}
}
