#include <string>
#include <vector>

using namespace std;
/*
	홀짝만 알면 풀 수 있는 문제...
*/
string solution(int n) {    
    string answer = "";
    for(int i = 0 ; i < n/2 ; i++)
        answer+= "수박";
    if(n&1)
        answer+="수";
    
    return answer;
}