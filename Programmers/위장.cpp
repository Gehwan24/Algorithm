#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int temp;
	map< string, int > m;
	//���� ������ ���� ī��Ʈ �������� ���������� Ȯ��
	for (int i = 0; i < clothes.size();i++)
	{
		if (m[clothes[i][1]])
			m[clothes[i][1]] += 1;
		else
			m[clothes[i][1]] = 1;
	}
	//+1�� ���Ѱ��� ������
	for (auto iter = m.begin(); iter != m.end();iter++)
	{
		temp = iter->second + 1;
		answer = answer * temp;
	}
	//-1���ָ� �� ����
	answer -= 1;
	return answer;
}
int main(void)
{
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses","eyewear" }, { "green_turban", "headgear" } };
	cout << solution(clothes);
}