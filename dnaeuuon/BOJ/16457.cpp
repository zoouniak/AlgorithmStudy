#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[21];
vector<int> v;
vector<int> M[100];
int answer = 0;
int n, m, k;

void combination(int depth, int start) {
	if (depth == n) {
		int result = 0;
		for (int i = 0; i < m; i++) {
			int count = 0;
			for (int j = 0; j < k; j++) {
				for (int l = 0; l < depth; l++) {
					if (arr[l] == M[i][j]) count++;
				}
			}
			if (count == k) result++;
			}
		if (answer < result) answer = result;
		}
	for (int i = start; i <= 2 * n; i++) {
		arr[depth] = v[i];
		combination(depth + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 1; i <= 2 * n; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int input;
			cin >> input;
			M[i].push_back(input);
		}
	}

	combination(0, 0);
	cout << answer;
}