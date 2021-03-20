#include <string>
#include <vector>

using namespace std;
/*
 네자리 빼꼬 전부 별표로 바꾸는 알고리즘을 구현한다
*/
string solution(string phone_number) {
    string answer = phone_number;
    for(int i = 0 ; i <phone_number.size()-4; i++)
        answer[i] = '*';
    return answer;
}