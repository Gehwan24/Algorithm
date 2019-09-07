#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size());
	for (int i = 0; i < heights.size();i++)
		answer[i] = 0;
	int temp = 0;
	for (int i = heights.size() - 1;i > 0;i--)
	{
		temp = heights[i];
		for (int j = i - 1;j >= 0;j--)
		{
			if (heights[j] > temp)
			{
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}