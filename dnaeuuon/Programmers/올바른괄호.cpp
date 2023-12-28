#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int left = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') left++;
        else {
            if(left > 0) left--;
            else return false;
        }  
    }
    
    if(left == 0) answer = true;
    else answer = false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
