#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// nums_len은 배열 nums의 길이입니다.
int solution(vector<int> nums) {
	int answer = 0;
	int sum = 0;
	int count = 2;
	int temp;

	for (int i = 0; i < nums.size();i++)
		sum += nums[i];
	int* odd = new int[sum + 1];

	for (int i = 0; i < sum + 1;i++)
		odd[i] = i;
	for (int i = 2; i < sum + 1;i++)
	{
		while (i*count < sum + 1)
		{
			odd[i*count] = 0;
			count++;
		}
		count = 2;
	}
	for (int i = 0; i < nums.size() - 2;i++)
		for (int j = i + 1; j < nums.size() - 1;j++)
			for (int k = j + 1; k < nums.size();k++)
				if (odd[nums[i] + nums[j] + nums[k]])
					answer++;
	return answer;

}