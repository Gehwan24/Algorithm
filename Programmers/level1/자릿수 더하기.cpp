#include <iostream>

using namespace std;
/*
 나누기 후 더하기 끝
*/ 
int solution(int n)
{
    int answer = 0;
    while(n){
        answer+= (n%10);
        n/=10;
    }
    return answer;
}