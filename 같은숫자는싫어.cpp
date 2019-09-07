#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	for (auto iter = arr.begin();iter != arr.end();iter++)
	{
		if (iter == arr.begin())
			answer.push_back(*iter);
		else
		{
			if (answer.back() == *iter)
				continue;
			else
				answer.push_back(*iter);
		}
	}
	return answer;
}