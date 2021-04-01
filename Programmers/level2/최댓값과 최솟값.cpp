#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 문자열을 스페이스바 단위로 나눈 뒤 
 최솟값 최댓값을 구해 이를 문자열로 반환한다.
*/
vector<string> split_token(string as){
    vector<string> tokens;
    int previous = 0, current;
    current = as.find(' ');
    while (current != string::npos)
    {
        string substring = as.substr(previous, current - previous);
        tokens.push_back(substring);
        previous = current + 1;
        current = as.find(' ',previous); 
    }
    tokens.push_back(as.substr(previous, current - previous));
    return tokens;
}

string solution(string s) {
    string answer = "";
    vector<string> tokens = split_token(s);
    int _max = -987654321;
    int _min = 987654321;
    
    for(string t : tokens){
        int temp = stoi(t);
        _max = _max < temp ? temp : _max;
        _min = _min > temp ? temp : _min;
    }
    answer = to_string(_min) +" " + to_string(_max);
    return answer;
}