#include <string>
#include <vector>

using namespace std;
/*
 필요한 개념 : 3진법
 변형 개념 : 3진법이지만 나누어 떨어지는 경우는 몫에서 1을 빼줘야
 해당 값이 구현이 된다.
*/
string solution(int n) {
    
    string answer = "";
    while(n){
       char tmp= (n%3) == 0 ? '4' : '0'+n%3; 
       answer  =   tmp+answer;
        n = (n%3) == 0 ? n/3 -1 : n/3;
    }
    return answer;
}