#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	int count = 0;
	int check = 0;
	vector<int> start;
	map <int,int> stick;
	vector<int> point;
	
	for (int i = 0; i < arrangement.size();i++)
	{
		if (arrangement[i] == '(')
			start.push_back(i);
		else if (arrangement[i] == ')')
		{
			if (arrangement[i - 1] == '(')
			{
				point.push_back(i - 1);
				start.pop_back();
			}
			else
			{
				stick[start.back()] = i;
				start.pop_back();
			}
		}
			
	}
	for (auto iter = stick.begin();iter!=stick.end();iter++)
	{
		count = 0;
		for (int j = 0; j < point.size();j++)
		{
			if (iter->first<= point[j] && point[j] <= iter->second)
				count++;
		}
		if (count != 0)
			answer = answer + count + 1;
	}
	return answer;
}


int main(void)
{
	string a = "()(((()())(())()))(())";
	cout << solution(a) << endl;
}