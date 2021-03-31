#include <string>
#include <vector>
#include <map>
using namespace std;
/*
	map을 이용해 각 의류 종류 수를 분류하고 (각 종류 수 +1)씩 곱하기
	마지막에 아무것도 안입은걸 고려해 -1 하고 반환
*/
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> m;
    for(int i = 0; i < clothes.size(); i++)
    {
        if(m[clothes[i][1]])
            m[clothes[i][1]]++;
        else
            m[clothes[i][1]] = 1;
    }
    answer = 1;
    for(auto iter = m.begin(); iter!= m.end(); iter++)
    answer *= (iter->second+1);
    answer--;
    return answer;
}