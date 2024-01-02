#include <string>
#include <sstream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int prev = 0; // 이전 위치
    int curr = s.find(' '); // 현재 위치
    
    while(curr != string::npos)
    {
        string tmp = s.substr(prev, curr - prev);
        for(char& ch: tmp) ch = tolower(ch);
        tmp[0] = toupper(tmp[0]);
        answer += tmp;
        answer += " ";
        prev = curr + 1;
        curr = s.find(" ", prev);
    }
    string tmp = s.substr(prev, curr - prev);
    for(char& ch: tmp) ch = tolower(ch);
    tmp[0] = toupper(tmp[0]);
    answer += tmp;
    
    return answer;
}
