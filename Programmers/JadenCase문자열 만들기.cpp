#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = s;
	bool space = false;
	if (isalpha(answer[0]))
	{
		if (!isupper(answer[0]))
			answer[0] = toupper(answer[0]);
	}
	for (int i = 1; i < s.size(); i++)
	{
		if (answer[i] == ' ')space = true;
		else
		{
			if (space)
			{
				if (isalpha(answer[i]))
				{
					if (!isupper(answer[i]))
						answer[i] = toupper(answer[i]);
				}
				space = false;
			}
			else
			{
				if (isalpha(answer[i]))
				{
					if (isupper(answer[i]))
						answer[i] = tolower(answer[i]);
				}
			}
				
		}
	}
	return answer;
}