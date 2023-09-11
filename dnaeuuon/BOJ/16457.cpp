#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[21];
vector<int> M[100];
int n, m, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;

	vector<int> v;
	for (int i = 1; i < 2 * n; i++) {
		v.push_back(i);
	}
	vector<bool> temp(v.size(), false);
	for (int i = 0; i < n; i++) {
		temp[i] = true;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int input;
			cin >> input;
			M[i].push_back(input);
		}
	}

	int max = 0;
	do {
		int depth = 0;
		int result = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (temp[i] == true) {
				arr[depth++] = v[i];
			}		
		}
		for (int i = 0; i < m; i++) {
			int count = 0;
			for (int j = 0; j < k; j++) {
				for (int l = 0; l < depth; l++) {
					if (arr[l] == M[i][j]) count++;
				}
			}
			if (count == k) result++;
		}
		if (max < result) max = result;
	} while (next_permutation(v.begin(), v.end()));

	cout << max;
}