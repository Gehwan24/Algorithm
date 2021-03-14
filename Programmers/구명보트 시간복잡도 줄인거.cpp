#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;
	int count = 0;
	vector<int> big;
	vector<int> small;
	for (int i = 0; i < people.size();i++)
	{
		if ((limit / 2) >= people[i])
			small.push_back(people[i]);
		else
			big.push_back(people[i]);
	}
	sort(small.begin(), small.end(),greater<int>());
	sort(big.begin(), big.end());

	while (1)
	{
		if (small.empty() || big.empty())break;
		if (small.back() + big.front()>limit)break;
		if (small.back() + big.back() <= limit)
		{
			small.pop_back();
			big.pop_back();
			count++;
		}
		else
		{
			big.pop_back();
			answer++;
		}
	}
	answer += big.size() + count;
	if (small.size() % 2)
		answer += small.size() / 2 + 1;
	else
		answer += small.size() / 2;
	return answer;

}
