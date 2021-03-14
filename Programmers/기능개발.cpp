#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	int count = 0;
	int temp;
	//³¯Â¥ 
	for (int i = 0; i < progresses.size();i++)
	{
		temp = 100 - progresses[i];
		if (temp%speeds[i] == 0)
			day.push_back(temp / speeds[i]);
		else
			day.push_back((temp / speeds[i])+1);
	}
	for (int i = 0; i < day.size();i++)
	{
		if (i == 0)
		{
			temp = day[0];
			count++;
		}
		else
		{
			if (temp < day[i])
			{
				answer.push_back(count);
				temp = day[i];
				count = 1;
			}
			else
			{
				count++;
			}
		}
		if (i == day.size() - 1)
			answer.push_back(count);
	}
	
	return answer;
}

