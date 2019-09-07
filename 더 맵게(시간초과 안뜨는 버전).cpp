#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int temp = 0;
	priority_queue<int,vector<int>, greater<int>> que;
	for (int i = 0; i < scoville.size();i++)
		que.push(scoville[i]);
	while (1)
	{
		if (que.size() == 1)
		{
			if (que.top() < K)
				return -1;
			else
				return answer;
		}
		if (que.top() >= K)break;
		else
		{
			temp = que.top();
			que.pop();
			temp += que.top() * 2;
			que.pop();
			que.push(temp);
			answer++;
		}
	}
	return answer;
}