#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for (int i = 0; i < A.size(); i++)
    {
        int result = A[i] * B[i];
        answer += result;
    }
    
    
    return answer;
}
