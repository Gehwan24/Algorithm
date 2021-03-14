#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int count = 0;
	
	//참가자 이름에 알맞게 숫자카운트를 센 map 을 생성한다
	map< string, int > m;
	for (int i = 0; i < participant.size();i++)
	{
		//동명이인일시 +1
		if(m[participant[i]])
			m[participant[i]] +=1;
		//아닐시 1
		else
			m[participant[i]] = 1;
	}
	//완주한 사람일때 -1 해준다
	for (int i = 0; i < completion.size(); i++)
	{
		m[completion[i]] -= 1;
	}
	//1이 남아있는 키값이 완주하지 못한 선수이다
	for (auto it = m.begin(); it != m.end();it++)
	{
		if (it->second != 0)
			answer += it->first;
	}
	return answer;
}

int main(void)
{
	vector<string> a = { "leo", "kiki", "eden" };
	vector<string> b = { "kiki", "eden" };

	
	cout << solution(a, b) << endl;
}