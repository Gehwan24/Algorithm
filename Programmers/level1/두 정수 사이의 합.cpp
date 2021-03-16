#include <string>
#include <vector>

using namespace std;

/*
필요한 자료구조 : X

 범위만 고려 잘하면 될듯?
 long long 과 int의 범위의 차이 
*/
long long solution(int a, int b) {
    long long answer = 0;
    for(int i = (a>b ? b: a); i <= (a >b ? a : b); i++)
        answer+=i;
    return answer;
}