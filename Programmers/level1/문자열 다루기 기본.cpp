#include <string>
#include <vector>

using namespace std;

/*
 필요한 자료구조 : 없는듯?
 조건에 알맞게 구현하고, isdigit 함수를 이용해 숫자인지 아닌지 판독하기
*/
bool solution(string s) {
    if(!(s.size() == 4 || s.size() == 6))
        return false;
    for(int i = 0 ; i <s.size(); i++)
    {
        if(!isdigit(s[i]))
            return false;
    }    
    return true;
}