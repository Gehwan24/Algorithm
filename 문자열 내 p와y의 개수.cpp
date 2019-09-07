#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int count_s = 0;
	int count_p = 0;
	for (int i = 0; i < s.size();i++)
	{
		if (s[i] == 'y'||s[i] == 'Y') count_s++;
		else if (s[i] == 'p'|| s[i] == 'P') count_p++;
	}
	if (count_s != count_p)
		return false;
	return answer;
}