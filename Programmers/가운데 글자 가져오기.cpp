#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	//���ڿ� ���̰� ¦���� �� �ΰ��� ���� return
	if (s.size() % 2 == 0)
	{
		answer += s[s.size() / 2 - 1];
		answer += s[s.size() / 2];
	}
	//Ȧ���� ��� �Ѱ� ���� return
	else
	{
		answer += s[s.size() / 2];
	}
	return answer;
}