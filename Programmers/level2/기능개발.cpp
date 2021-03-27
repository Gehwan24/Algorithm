#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*
 쓸만한 자료구조 : map
 끝나는 날짜를 map으로 구현해 마감일이 이전에 가장 늦게끝난 기간보다 더 이르면
 마감일이 가장 늦게 끝난 일정으로 바꿔줌으로서 
 '뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.'
 의 조건을 충족시켜줌
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map<int,int> m;
    for(int i = 0 ; i < progresses.size(); i++){
        int left = (100-progresses[i])%speeds[i];
        int day = left ? (100-progresses[i])/speeds[i] + 1 : (100-progresses[i])/speeds[i];
        if(m.empty()){
            m[day] = 1;
        }else{
            if(m.rbegin()->first > day)day =m.rbegin()->first; 
            if(m[day])
                m[day]++;
            else
                m[day] = 1;
        }
    }
    for(auto iter = m.begin(); iter!= m.end(); iter++)
        answer.push_back(iter->second);
    return answer;
}