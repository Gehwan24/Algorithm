#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> hawi = scoville;
	int temp;
	int temp2;
	int total = 0;
	sort(hawi.begin(), hawi.end());
	for (int i = 0; i < hawi.size();i++)
	{
		if (hawi[i] >= K)
			answer = i-1;
		else
		{

		}
	}
	return answer;
}