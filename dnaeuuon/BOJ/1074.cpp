#include <iostream>
#include <math.h>
using namespace std;

int Z(int N, int r, int c) {
	if (N <= 0) {
		return 0;
	}
	int mid = (1 << N) / 2;
	int cnt = mid * mid;

	if (r < mid) {
		if (c < mid) {
			return (cnt * 0) + Z(N - 1, r, c);
		}
		else {
			return (cnt * 1) + Z(N - 1, r, c - mid);
		}
	}
	else {
		if (c < mid) {
			return (cnt * 2) + Z(N - 1, r - mid, c);
		}
		else {
			return (cnt * 3) + Z(N - 1, r - mid, c - mid);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;
	
	cout << Z(N, r, c);
}