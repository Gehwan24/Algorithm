#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
필요한 자료구조 : 없음
해당 문제는 나누어 떨어지는 지만 확인하면 되는 문제
*/
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i : arr){
        if(i % divisor)
            continue;
        answer.push_back(i);    
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}