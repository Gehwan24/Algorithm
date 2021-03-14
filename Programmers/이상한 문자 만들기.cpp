#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int count = 1;
	char* temp = (char*)s.c_str();
	for (int i = 0;i < s.size(); i++)
	{
		if (!isalpha(temp[i]))
		{
			count = 1;
			continue;
		}
		if (isalpha(temp[i]))
		{
			if (count % 2 == 1)
				temp[i] = toupper(temp[i]);
			else
				temp[i] = tolower(temp[i]);
			count++;
		}
	}
	answer = temp;
	return answer;
}

int main(void)
{
	string s = "try hello world";
	cout << solution(s) << endl;
}