#include <string>
#include <vector>

using namespace std;
/*
 나누어 떨어질 경우에는 약수이므로 해당 값 더해서 값 반환하면 정답
*/
int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n ; i++)
    {
        if(n%i)continue;
        answer+=i;
    }
    return answer;
}