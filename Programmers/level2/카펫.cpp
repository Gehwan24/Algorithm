#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
	먼저 카펫의 넓이를 구한뒤 
	나누어지는 값을 구한다.
	이후, -2씩 뺀 값의 곱이 안쪽 yellow의 숫자와 동일한지 비교해
	같으면 해당 값 두개를 반환한다.
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int _min = 987654321;
    int total = brown + yellow;
    pair<int,int> p;
    for(int i = 1; i <= sqrt(total); i++){
        if((total%i) == 0)
        {
            if((total/i -2) * (i-2) == yellow)
            {
                p = make_pair(total/i,i);
                break;
            }
        }
    }
    answer.push_back(p.first > p.second ? p.first : p.second); answer.push_back(p.first <= p.second ? p.first : p.second);
    return answer;
}