#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 필요한 자료구조 : string 
 알면 좋은 기능 : rbegin(), assign()
 할당과 역순을 이용해 역정렬 진행
*/
string solution(string s) {
    string answer = s;
    sort(answer.begin(),answer.end());
    answer.assign(answer.rbegin(),answer.rend());
    return answer;
}