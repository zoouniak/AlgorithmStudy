#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<char> v;
	int count = 0;
	int index = 0;
	char temp;

	for (int i = 0; i < str.length(); i++) {
		if ((isdigit((char)str[i]))) {
			count += str[i] - '0';
			index++;
		}
		else
			v.push_back(str[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i);
	}
	cout << count << endl;
}