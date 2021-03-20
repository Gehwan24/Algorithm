#include <string>
#include <vector>

using namespace std;
/*
  필요한 개념 : vector
	vector에 먼저 필요한 만큼 할당하고 각 인덱스별 곱셈을 통해 진행
*/
vector<long long> solution(int x, int n) {
    vector<long long> answer(n,x);
    for(int i = 1; i <=n ; i++)
        answer[i-1] *= i;
    return answer;
}