#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int count = 0;
	
	//������ �̸��� �˸°� ����ī��Ʈ�� �� map �� �����Ѵ�
	map< string, int > m;
	for (int i = 0; i < participant.size();i++)
	{
		//���������Ͻ� +1
		if(m[participant[i]])
			m[participant[i]] +=1;
		//�ƴҽ� 1
		else
			m[participant[i]] = 1;
	}
	//������ ����϶� -1 ���ش�
	for (int i = 0; i < completion.size(); i++)
	{
		m[completion[i]] -= 1;
	}
	//1�� �����ִ� Ű���� �������� ���� �����̴�
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