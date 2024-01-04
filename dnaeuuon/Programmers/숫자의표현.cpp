#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count = 0;
    int index = 1;
    for (int i = 1; i <= n; i++)
    {
        count += i;
        if(count == n) answer++;
        else if(count > n) 
        {
            for(int j = index; j <= i; j++)
            {
                count -= j;
                index++;
                if(count == n) answer++;
                else if(count < n) break;
            }
        }
    }
    return answer;
}
