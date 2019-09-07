#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	map<int, int> temp;
	int size = nums.size()/2;
	for (int i = 0; i < nums.size(); i++)
	{
		if (temp[nums[i]])
			temp[nums[i]]++;
		else
			temp[nums[i]] = 1;;
	}
	if (size < temp.size())answer = size;
	else answer = temp.size();
	return answer;
}