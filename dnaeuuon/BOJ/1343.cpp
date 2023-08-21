#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	string result = "";
	int count = 0;
	bool failed = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'X') count++;
		if (count == 4) {
			result += "AAAA";
			count = 0;
		}
		if (str[i] == '.') {
			if (count == 2) {
				result += "BB";
				count = 0;
			}
			else if (count == 0) {
			}
			else failed = true;
			result += ".";
			count = 0;
		}
	}
	if (count == 4)
		result += "AAAA";
	else if (count == 2)
		result += "BB";
	else if (count == 0);
	else failed = true;

	if (failed) cout << -1;
	else cout << result;
}