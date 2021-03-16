#include <string>
#include <vector>

using namespace std;

/*
 그냥 인덱스 찾아서 해당 값 문자열로 변환해서 반환
*/
string solution(vector<string> seoul) {
    int count = 0;
    for(string s : seoul){
        if(s == "Kim")
            break;
        else
            count++;
    }
    string answer ="김서방은 ";
    if(count < 10)
        answer+=(count+'0');
    else
        answer+=to_string(count);
    answer+="에 있다";
    return answer;
}