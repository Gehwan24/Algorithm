#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	if (phone_book.size() >= 2)
	{
		for (int j = 0; j < phone_book.size();j++)
		{
			for (int k = 0; k < phone_book.size();k++)
			{
				if (j == k)
					continue;
				if (strncmp(phone_book[j].c_str(), phone_book[k].c_str(), phone_book[j].size()) == 0)
				{
					answer = false;
					return answer;
				}
			}
		}

	}

	return answer;
}

int main(void)
{
	vector<string> index = { "119","97674223","11923432532" };
	cout << solution(index)<<endl;
}