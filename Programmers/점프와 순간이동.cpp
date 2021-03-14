#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
	int ans = 0;
	vector<int> jump;
	int tmp = n;
	while (tmp != 1)
	{
		if (tmp % 2)
			jump.push_back(1);
	}
	jump.push_back(1);
	ans = jump.size();

	return ans;
}