#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	for (auto iter = arr.begin();iter != arr.end();iter++)
	{
		if (iter == arr.begin())
			answer.push_back(*iter);
		else
		{
			if (answer.back() == *iter)
				continue;
			else
				answer.push_back(*iter);
		}
	}
	return answer;
}