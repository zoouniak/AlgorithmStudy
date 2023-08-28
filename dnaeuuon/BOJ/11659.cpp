#include <iostream>
using namespace std;
long long arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int input;
	cin >> input;
	arr[1] = input;

	for (int i = 2; i <= N; i++) {
		int input;
		cin >> input;
		arr[i] = input + arr[i - 1];
	}
	for (int a = 0; a < M; a++) {
		int i, j;
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}
}