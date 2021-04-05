/*
	두 가지의 조건을 잘 활용하면 쉽게 구현이 가능
	- 기존에 나온 단어 사용시 return
	- 전의 뒷글자와 현재 말한 문자열의 맨 앞자리가 일치해야 한다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string,int> m;
    vector<int> answer(2,0);
    
    char before = words[0][0];
    for(int i = 0 ; i < words.size(); i++){
        if(words[i][0] != before)
        {
            answer[0] = i%n + 1;
            answer[1] = i/n + 1;
            break;
        }
        else{
            if(m[words[i]])
            {
                answer[0] = i%n + 1;
                answer[1] = i/n + 1;
                break;
            }
            else{
                m[words[i]] = 1;
                before = words[i][words[i].size()-1];
            }
        }
    }    

    return answer;
}