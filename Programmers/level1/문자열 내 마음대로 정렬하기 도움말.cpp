#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
	필요한 자료구조 : map 
	알면 좋은거 : 정렬
	사전순으로 정렬후, 다시 해당 문자별로 존재하는 단어 재정렬
	이후, 순차적으로 answer에 넣어 정렬된 상태를 유지시킨다.
*/
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<char,vector<string>> m;
    for(int i = 0; i < strings.size(); i++)
    {
        m[strings[i][n]].push_back(strings[i]);
    }
    for(auto iter = m.begin(); iter != m.end(); iter++){
        sort(iter->second.begin(),iter->second.end());
        for(int i = 0 ; i < iter->second.size(); i++)
            answer.push_back(iter->second[i]);
    }
    return answer;
}