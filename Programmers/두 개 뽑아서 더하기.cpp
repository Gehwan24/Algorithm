#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 필요한 자료구조 : 없다..?
 그냥 중복만 제거하면 될듯
 내가 푼 방식의 단점 : 모든 숫자를 answer 에 push_back 하기 때문에 size가 커질수록 memory leak이 발생할 수 있음
 set이나 map 쓰는게 더 나을듯?
 생각한 최적 답(다른 사람 풀이) : 
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <set>
    using namespace std;

    vector<int> solution(vector<int> numbers) {
        vector<int> answer;
        set<int> st;
        for(int i = 0;i<numbers.size();++i){
            for(int j = i+1 ; j< numbers.size();++j){
                st.insert(numbers[i] + numbers[j]);
            }
        }
        answer.assign(st.begin(), st.end());
        return answer;
    }
*/
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0 ; i < numbers.size(); i++)
        for(int j = 0 ; j < numbers.size(); j++)
            if(i!=j)answer.push_back(numbers[i]+numbers[j]);
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    return answer;
}