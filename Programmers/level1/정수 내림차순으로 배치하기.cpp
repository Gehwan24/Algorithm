#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 순서대로 벡터에 저장한 뒤, 정렬을 진행한다.
 진행 이후에 하나씩 뒤에서 뽑아서 자릿수에 더해주면 정렬된 큰 수가 나온다
*/
long long solution(long long n) {
    long long answer = 0;
    vector<int> each_num;
    while(n){
        each_num.push_back(n%10);
        n/=10;
    }
    sort(each_num.begin(),each_num.end());
    while(!each_num.empty()){
        answer= answer * 10 + each_num.back();
        each_num.pop_back();
    }
    return answer;
}