#include <string>
#include <iostream>
using namespace std;

/*
 이건 솔직히 그냥 .... 네 비교해서 값 구하면 됩니다.
*/
bool solution(string s)
{
    int p = 0,y = 0;
    for(int i = 0 ; i < s.size(); i++){
    if(s[i] == 'p'||s[i] == 'P')
        p++;
    if(s[i] == 'y'||s[i] == 'Y')
        y++;
    }
    
        return (p == y) ? true : false;
}