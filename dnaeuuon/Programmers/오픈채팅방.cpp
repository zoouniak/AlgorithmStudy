#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    vector<string> tmp;
    map<string, string> result;
    
    for(int i = 0; i < record.size(); i++) 
			{
        stringstream ss(record[i]);
        string temp;
        
        while(getline(ss, temp, ' ')) 
				{
            tmp.push_back(temp);
        }
        
        if(tmp[0] == "Enter") 
				{
            result[tmp[1]] = tmp[2];
        }
        else if(tmp[0] == "Change") 
				{
            result[tmp[1]] = tmp[2];
        }
        tmp.clear();
    }
    
    for(int i = 0; i < record.size(); i++) 
		{
        stringstream ss(record[i]);
        string temp;
        
        while(getline(ss, temp, ' ')) 
				{
            tmp.push_back(temp);
        }
        if(tmp[0] == "Enter") 
				{
            answer.push_back(result[tmp[1]] + "님이 들어왔습니다.");
        }
        else if(tmp[0] == "Leave") 
				{
            answer.push_back(result[tmp[1]] + "님이 나갔습니다.");
        }
        tmp.clear();
    }
    
    return answer;
}
