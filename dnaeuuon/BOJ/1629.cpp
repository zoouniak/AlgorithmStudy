#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long int k;

long long int power(int A, int B, int C)
{
	if (B == 0) return 1;
	if (B == 1) return A % C;

	k = power(A, (B / 2), C) % C; // 이게 중요 포인트
	if ((B % 2) == 0) return k * k % C;
	else return k * k % C * A % C;
}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);

	long long int A, B, C;
	cin >> A >> B >> C;
	
	cout << power(A, B, C);
}
