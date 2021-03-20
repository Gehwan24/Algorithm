#include <string>
#include <vector>

using namespace std;

/*
  문제에 주어진 요구사항에 알맞게 구현하면 종료
*/
int solution(int num) {
    int answer = 0;
    long long temp = num;
    while(temp != 1 && answer < 500){
        temp = (temp&1) ?  temp*3 + 1 : temp/2;
        answer++;
    }
    if(answer == 500)answer = -1;
    return answer;
}