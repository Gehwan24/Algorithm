#include <string>
#include <vector>

using namespace std;
/*
 이것도 단순히 문제 요구사항에 알맞게 구현하면 된다
*/
double solution(vector<int> arr) {
    double answer = 0;
    for(int i : arr)
        answer+=i;
    return answer/arr.size();
}