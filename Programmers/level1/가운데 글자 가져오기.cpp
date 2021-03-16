#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 필요한 자료구조 : 딱히 없음
 필요한 개념 : 딱히없음 
 그냥 짝수면 두개, 홀수면 한개 반환하기
*/
string solution(string s) {
    string answer ="";
    if(s.size()&1){
        answer+=s[s.size()/2];
    }
    else{
        answer = s.substr(s.size()/2 -1 ,2 );
    }
    return answer;
}