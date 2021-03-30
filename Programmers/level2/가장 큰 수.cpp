#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
	필요한 개념 : 문자열도 비교가 가능하다!
	쓰면 유용한 알고리즘 : sort,compare
	문자열을 비교해서 두개를 합쳤을 때 더 큰 수가 나오도록
	정렬을 진행한다
*/
bool compare(string a,string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    for(int i = 0; i< numbers.size(); i++)
        num.push_back(to_string(numbers[i]));
    sort(num.begin(),num.end(),compare);
    for(string t : num)
        answer+=t;
    for(int i = 0; i < answer.size(); i++)
        if(answer[i]!='0')
            return answer;
    return "0";
}