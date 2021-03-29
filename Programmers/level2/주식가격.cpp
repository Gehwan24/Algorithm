#include <string>
#include <vector>

using namespace std;
/*
	해당 문제는 현재 인덱스 기준으로 for문을 돌려
	어떤 인덱스가 더 작은 값인지 비교를 진행한다.
	마지막 인덱스까지 비교했으나 작은 값이 나오지않아 break문에 걸리지 않을 경우
	마지막 인덱스 - 현재 인덱스를 진행한다.
*/
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    for(int i = 0 ; i < prices.size()-1; i++){
        for(int j = i+1; j< prices.size(); j++)
        {
            if(prices[i] <= prices[j])
                ;
            else{
                answer[i] = j-i;
                break;
            }
            if(j == prices.size()-1)
                answer[i] = j - i;
        }
    }
    return answer;
}