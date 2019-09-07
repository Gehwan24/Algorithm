#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
	vector<char> temp;
	int answer = 0;
	char ass;
	if (s.size() % 2)return 0;
	else
	{
		temp.push_back(s[0]);
		for (int i = 1; i < s.size();i++)
		{
			if (temp.empty())
				temp.push_back(s[i]);
			else
			{
				ass = temp.back();
				if (s[i] == ass)temp.pop_back();
				else
					temp.push_back(s[i]);
			}
		}
	}
	if (temp.empty())return 1;
	else
		return answer;
}