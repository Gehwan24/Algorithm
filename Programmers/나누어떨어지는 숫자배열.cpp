#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool esc(int a, int b)
{
	return a < b;
}
vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	for (auto iter = arr.begin(); iter != arr.end();iter++)
		if (*iter%divisor == 0)
			answer.push_back(*iter);
	if (answer.empty())
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end(), esc);
	return answer;
}