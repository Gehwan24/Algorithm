#include <string>
#include <vector>

using namespace std;
/*
	단어로 분리될 경우(스페이스바)
	카운트를 0으로 초기화한뒤 짝수는 대문자 홀수는 소문로 변경
*/
string solution(string s) {
    string answer = s;
    int c = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(isalpha(answer[i])){
            if(c&1)
                answer[i] = answer[i] <= 'Z' ? answer[i]+32 : answer[i];
            else
                answer[i] = answer[i] >= 'a' ? answer[i]-32 : answer[i]; 
            c++;
        }
        else
            c = 0;
    }
    return answer;
}