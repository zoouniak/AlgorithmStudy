#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

string solution(string s) {
    string answer = "";
    stack<char> stack;
    vector<int> v;
    
    for (char ch : s)
        stack.push(ch);
    
    int num = 0;
    int temp = 0;
    int degree = 0;
    while (!stack.empty())
    {
        char ch = stack.top();
        stack.pop();
        
        if(ch == '-') 
        {
            v.push_back(-num);
            num = 0;
            degree = 0;
            if(!stack.empty()) stack.pop();
        }
        else if(ch == ' ') {
            v.push_back(num);
            num = 0;
            degree = 0;
        }
        else 
        {
            temp = ch - '0';
            num += pow(10, degree) * temp;
            degree++;
        }
    }
    
    if(num > 0) v.push_back(num);
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front());
    answer += " ";
    answer += to_string(v.back());
    
    return answer;
}
