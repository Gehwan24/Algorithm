#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int count = 0;
	sort(d.begin(), d.end());
	for (auto iter = d.begin();iter != d.end();iter++)
	{
		if (count + *iter > budget)
			break;
		else
		{
			count += *iter;
			answer++;
		}
	}
	return answer;
}