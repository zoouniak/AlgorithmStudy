#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int index = 1;
	while (true) {
		stack<char> s;
		string str;
		cin >> str;

		if (str.find('-') != string::npos) break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '{') s.push('{');
			else {
				if (!s.empty()) {
					if (s.top() == '{') s.pop();
					else s.push('}');
				}
				else s.push('}');
			}
		}

		int result = 0;
		while (!s.empty()) {
			char c = s.top();
			s.pop();
			if (c == '{') {
				if (s.top() == '{') {
					result++;
					s.pop();
				}
				else {
					result += 2;
					s.pop();
				}
			}
			else {
				if (s.top() == '}') {
					result++;
					s.pop();
				}
			}
		}
		cout << index++ << ". "<< result << '\n';
	}
}