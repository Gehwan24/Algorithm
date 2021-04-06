#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 띄어쓰기만 확인해서 각 첫 글자가 대문자가 되도록 구현하면 쉽다
*/
string solution(string s) {
    string answer = s;
    bool split =true; 
    for(int i = 0 ; i <answer.size(); i++)
    {
        if(isalpha(answer[i])){
            if(split)
            {
                answer[i] = answer[i] >=97 ? answer[i]-32 : answer[i];                    
                split = false;
            }
            else{
                answer[i] = answer[i] <97 ? answer[i]+32 : answer[i];
            }
        }
        else{
            if(split)
                split = false;
            if(answer[i] == ' ')
                split = true;
            }
    }
    
    return answer;
}