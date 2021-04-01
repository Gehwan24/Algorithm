#include <string>
#include <vector>

using namespace std;
/*
 알아야 할 개념 : 피보나치
 세개의 수로 계속해서 피보나치 수를 찾아가면 된다.
*/
int solution(int n) {
    int answer = 1;
    int temp = n-2;
    int before = 1;
    if(n==1)return 1;
    while(temp){
        int tmp = answer;
        answer =(answer+before)%1234567;
        before = tmp;
        temp--;
    }
    return answer;
}