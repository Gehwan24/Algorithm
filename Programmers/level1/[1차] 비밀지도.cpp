#include <string>
#include <vector>

/*
 필요한 개념 : | (or)
 숫자를 | 시켜 먼저 비트를 변경해주고 
 각 숫자를 2진법으로 환산해 # 또는 ' '로 변환해준다
 최종적으로 해당 문자열을 추가해주면 된다.
*/
using namespace std;
string int_to_str(int x,int n){
    string answer = "";
    while(x){
        answer =(x&1 ?'#':' ')+answer;
        x/=2;
    }
    while(answer.size() != n)
        answer = " "+answer;
    return answer;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0 ; i < n ; i++)
      answer.push_back(int_to_str(arr1[i]|arr2[i],n));
    return answer;
}