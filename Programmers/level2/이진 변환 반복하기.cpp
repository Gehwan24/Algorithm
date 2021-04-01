#include <string>
#include <vector>

using namespace std;
/*
	0을 제거한다
	문자열의 길이를 확인한다
	이를 2진법으로 구현한다.
	이를 반복한다.
	1이 나올 경우 while문 종료
*/
vector<int> solution(string s) {
    string t = s;
    vector<int> answer(2,0);
    while(t != "1"){
        answer[0]++;
        int count = 0;
        string sub_zero = "";
        for(char ch : t)
        {
            if(ch == '1') sub_zero+=ch;
            else count++;
        }
        answer[1]+= count;
        int length = sub_zero.size();
        string tmp = "";
        while(length){
            tmp += ( (length%2) + '0');
            length/=2;
        }
        t = tmp;
    }
    return answer;
}