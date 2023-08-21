#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long S;
	cin >> S;
	
	long long result = 0;
	long long i = 1;
	while (S >= result) {
		result += i;
		i++;
	}
	cout << i - 2;
}