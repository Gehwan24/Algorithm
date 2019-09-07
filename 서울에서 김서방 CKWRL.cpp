#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int count = 0;
	for (auto iter = seoul.begin();iter != seoul.end();iter++)
	{
		if (*iter == "Kim")
			answer="김서방은 "+to_string(count)+"에 있다";
		else
			count++;
	}
	return answer;
}

int main(void)
{
	vector<string> seoul = { "Jane", "Kim" };
	cout << solution(seoul) << endl;
}