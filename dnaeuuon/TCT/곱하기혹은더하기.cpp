#include <iostream>
#include <string>
using namespace std;
int n[21];

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		n[i] = str[i] - '0';
	}
	int result = (int)n[0];
	for (int i = 1; i < str.length(); i++) {
		int num = (int)n[i];
		if (result <= 1 || num <= 1) {
			result += num;
		}
		else {
			result *= num;
		}
	}
	cout << result << endl;
}