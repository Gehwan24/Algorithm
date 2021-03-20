#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 필요한 개념 : vector내부에 해당 수가 존재하는지 확인하는 방법
 그냥 단순히 for문을 돌아도 되지만 
 vector의 find 기능을 사용해봐도 좋을듯?
*/
vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    answer.erase(find(answer.begin(),answer.end(),*min_element(answer.begin(),answer.end())));
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}