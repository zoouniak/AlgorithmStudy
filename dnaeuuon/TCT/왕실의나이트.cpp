#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int x, y;
	int count = 0;
	
	int nx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int ny[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

	for (int i = 0; i < 8; i++) {
		x = str[0] - 'a';
		y = str[1] - '1';
		x = x + nx[i];
		y = y + ny[i];
		if ((x > -1 && y > -1) && (x < 8 && y < 8)) count++;
	}
	cout << count << endl;
}