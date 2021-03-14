#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	vector<int> rem;
	sort(people.begin(), people.end());
	vector<int> ::iterator iter = people.begin();
	
	while (!people.empty())
	{
		if (people.size() == 1) {
			answer++;
			break;
		}
		if (*iter + people.back() <= limit)
		{
			people.erase(iter);
			people.pop_back();
			answer++;
		}
		else
		{
			rem.push_back(people.back());
			people.pop_back();
		}
	}
	answer += rem.size();
	return answer;
}
