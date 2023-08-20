#include <iostream>
#include <math.h>
using namespace std;
int num[100001] = { 0, };

int main() {
	int N;
	cin >> N;

	num[1] = 1;
	num[2] = 2;

	for (int i = 3; i <= N; i++) {
		num[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (num[i] > num[i - j * j] + 1)
				num[i] = num[i - j * j] + 1;
		}
	}
	cout << num[N];
}