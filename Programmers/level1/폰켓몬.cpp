#include <vector>
#include <algorithm>
using namespace std;

/*
 필요한 자료구조 : vector
 해당 문제는 최대로 가질 수 있는 몬스터의 수가 n/2이기 때문에 
 모든 포켓몬 종류가 이보다 작을 경우 해당 값이 정답이 되고, 크거나 같을경우
 n/2가 답이된다.
*/
int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    answer = arr.size() > nums.size()/2 ? nums.size()/2 : arr.size();
    return answer;
}
