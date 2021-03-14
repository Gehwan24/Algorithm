#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	//문자열 길이가 짝수일 때 두개의 문자 return
	if (s.size() % 2 == 0)
	{
		answer += s[s.size() / 2 - 1];
		answer += s[s.size() / 2];
	}
	//홀수일 경우 한개 문자 return
	else
	{
		answer += s[s.size() / 2];
	}
	return answer;
}