#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int index = 0;
bool esc(string a, string b)
{
	if (a.at(index) == b.at(index))
	{
		if (a.compare(b) < 0)
			return true;
		else
			return false;
	}
	return a.at(index) < b.at(index);
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	index = n;
	sort(strings.begin(), strings.end(), esc);
	for (auto iter = strings.begin();iter != strings.end();iter++)
		answer.push_back(*iter);
	return answer;
}