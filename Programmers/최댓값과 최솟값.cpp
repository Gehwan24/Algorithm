#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int count = 1;
	int start = 0;
	string temp;
	vector<int> real;
	for (int i = 0; i < s.size();i++)
	{
		if (s[i] == ' ')
		{
			temp = s.substr(start, count);
			real.push_back(atoi(temp.c_str()));
			start = i+1;
			count = 1;
		}
		else
			count++;
	}
	temp =s.substr(start, count);
	real.push_back(atoi(temp.c_str()));

	answer = to_string(*min_element(real.begin(), real.end())) + " " + to_string(*max_element(real.begin(), real.end()));
	return answer;
}