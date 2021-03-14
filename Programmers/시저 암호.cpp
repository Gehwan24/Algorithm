#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	char* temp = (char*)s.c_str();
	for (int i = 0; i < s.size();i++)
	{
		if (65 <= temp[i] && temp[i] <= 90 && temp[i] + n > 90)
			temp[i] = (temp[i] + n) % 90 + 64;

		else if (97 <= temp[i] && temp[i] <= 122 && temp[i] + n > 122)
			temp[i] = (temp[i] + n) % 122 + 96;
		else if(isalpha(temp[i]))
			temp[i] += n;
	}
	answer = temp;
	return answer;
}

