#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
필요한 자료구조 : 해시 맵
필요에 따라 복잡도가 다르기 때문에 최적화된 해시맵을 이용하는 것이 효율적이라 판단
unordered_map 사용

다른 사람 풀이 
- unordered_set
- sort 후 하나씩 비교하며 첫 차이가 발생한 string return

*/
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
		//완주자 넣고 참가자에서 존재하지 않은 친구 출력하기
    for(string name : completion){
        if(m[name]){
            m[name]++;
        }
        else
            m[name] = 1;
    }
    for(string name : participant){
        if(m[name] > 0)
            m[name]--;
        else
            answer = name;
    }
    return answer;
}