#include <iostream>
#include <vector>
using namespace std;
int ant[100];
int N;

int main() {
	int food[100] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		food[i] = input;
	}
	ant[0] = food[0];
	ant[1] = max(food[0], food[1]);
	
	for (int i = 2; i < N; i++) {
		ant[i] = max(ant[i - 1], ant[i - 2] + food[i]);
	}

	cout << ant[N - 1];
}