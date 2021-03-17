#include <string>
#include <vector>

using namespace std;
/*
 벡터에 한자리씩 넣어서 반환하기
*/
vector<int> solution(long long n) {
    vector<int> answer;
    while(n){
        answer.push_back(n%10);
        n/=10;
    }
    return answer;
}