#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int q = 0;
	for (int i = 0; i < s.size();i++)
	{
		if (s[i] == '(')
			q++;
		else
			q--;
		if (q < 0) {
			answer = false;
			break;
		}
	}
	if (q != 0)
		answer = false;

	return answer;
}