#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 필요한 개념 : 정렬? 
 벡터내의 최소값부터 계속해서 차감해 budget이 음수가 되는 포인트를 찾아
 해당 카운트를 반환한다.
*/
int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(int i : d)
    {
        if(budget - i >= 0)
        {
            answer++;
            budget-=i;
        }
        else
            break;
    }
    return answer;
}