#include<string>
#include <iostream>

using namespace std;

/*
	(를 +1 )를 -1로 생각하고 음수가 될 경우 바로 false;
	끝났을 경우 0일 경우에만 올바른 괄호이기에 true 반환
	아닌경우 false
*/
bool solution(string s)
{
    int count = 0;
    for( char ch : s){
        count = (ch == '(') ? count+1 : count-1;

        if(count < 0)return false;
    }
    return (count == 0) ? true : false;
}