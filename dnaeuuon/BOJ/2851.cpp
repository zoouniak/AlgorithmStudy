#include <iostream>
using namespace std;

int main() {
	int min = 101;
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		cnt += n;
		if (abs(100 - cnt) <= min) {
			min = abs(100 - cnt);
			result = cnt;
		}
	}
	cout << result;
}