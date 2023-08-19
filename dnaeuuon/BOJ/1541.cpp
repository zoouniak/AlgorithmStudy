#include <iostream>
#include <math.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int result = 0;
	int digit = 0;
	int index = 0;

	for (int i = str.length() -1; i >= 0; i--) {
		if (isdigit(str[i])) {
			if (index == 0) {
				digit += (str[i] - '0');
				index++;
			}
			else 
				digit += (str[i] - '0') * pow(10, index++);
		}
		else {
			if (str[i] == '-') {
				result -= digit;
				digit = 0;
				index = 0;
			}
			else if (str[i] == '+') {
				index = 0;
			}
		}
	}
	result += digit;
	cout << result;
}