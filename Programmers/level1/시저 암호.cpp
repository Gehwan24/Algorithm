#include <string>
#include <vector>

using namespace std;

/*
	필요한 지식 : 알파벳 char 숫자 정도?
	삼항연산자 사용하면 간단하게 구현 가능
*/
string solution(string s, int n) {
    string answer = "";
    for(int i = 0 ; i < s.size(); i++){
        if(isalpha(s[i]))
              answer+= (s[i] <= 'Z') ? ((s[i]-'A'+n)%26 + 'A'):((s[i]-'a'+n)%26 + 'a');
        else
            answer+=s[i];
    }
    return answer;
}