#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> num1 = {1,2,3,4,5};
    vector<int> num2 = {2,1,2,3,2,4,2,5};
    vector<int> num3 = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == num1[i % (num1.size())]) cnt1++;
        if(answers[i] == num2[i % (num2.size())]) cnt2++;
        if(answers[i] == num3[i % (num3.size())]) cnt3++;
    }
    
    if(cnt1 > cnt2) 
    {
        if(cnt1 > cnt3) answer.push_back(1);
        else if(cnt1 < cnt3) answer.push_back(3);
        else 
        {
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else if(cnt1 < cnt2) 
    {
        if(cnt2 > cnt3) answer.push_back(2);
        else if(cnt2 < cnt3) answer.push_back(3);
        else 
        {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    else 
    {
        if(cnt2 > cnt3) 
        {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(cnt2 < cnt3) answer.push_back(3);
        else 
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
