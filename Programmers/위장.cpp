#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int temp;
	map< string, int > m;
	//옷의 종류에 따라 카운트 증가시켜 가짓수별로 확인
	for (int i = 0; i < clothes.size();i++)
	{
		if (m[clothes[i][1]])
			m[clothes[i][1]] += 1;
		else
			m[clothes[i][1]] = 1;
	}
	//+1씩 더한값을 곱해줌
	for (auto iter = m.begin(); iter != m.end();iter++)
	{
		temp = iter->second + 1;
		answer = answer * temp;
	}
	//-1해주면 답 나옴
	answer -= 1;
	return answer;
}
int main(void)
{
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses","eyewear" }, { "green_turban", "headgear" } };
	cout << solution(clothes);
}