#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    sort(tangerine.begin(), tangerine.end());
    
    int count = 0;
    for (int i = 1; i < tangerine.size(); i++)
    {
        if(tangerine[i-1] != tangerine[i]) 
        {
            pq.push(make_pair(++count, tangerine[i-1]));
            count = 0;
        }
        else count++;
    }
    pq.push(make_pair(++count, tangerine[tangerine.size() - 1]));

    while(!pq.empty())
    {
        k -= pq.top().first;
        answer++;
        if(k > 0) pq.pop();
        else break;
    }
    
    return answer;
}
