#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	map<string, int> hawi;
	int count = 1;
	bool end = true;
	char temp;
	for (int i = 0 ; i < words.size();i++)
	{
		if (i==0)
		{
			temp = words[i][words[i].size()-1];
			hawi[words[i]] = 1;
			count++;
		}
		else
		{
			if (hawi[words[i]] ||words[i].size() == 1 ||temp != words[i][0])
			{
				end = false;
				break;
			}
			else
			{
				temp = words[i][words[i].size() - 1];
				hawi[words[i]] = 1;
				count++;
			}
		}
	}
	if (end)
	{
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}
	if (count % 3)
	{
		answer.push_back(count % n+1 );
		answer.push_back(count / n + 1);

	}
	else {
		answer.push_back(n);
		answer.push_back(count / n);

	}
	return answer;
}