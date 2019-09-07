#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> one = { 1,2,3,4,5 };
	vector<int> two = { 2,1,2,3,2,4,2,5 };
	vector<int> three = { 3,3,1,1,2,2,4,4,5,5 };
	int answer_temp[3] = { 0 };
	int count = 0;
	int max = -1;
	for (auto i = answers.begin() ; i !=answers.end();i++)
	{
		if (*i == one[count%5])
			answer_temp[0]++;
		if (*i == two[count %8])
			answer_temp[1]++;
		if (*i == three[count%10])
			answer_temp[2]++;
		count++;
	}
	//이 아래부분 max_element로 대체 가능
	if (answer_temp[0] > answer_temp[1])
		max = answer_temp[0];
	else
		max = answer_temp[1];
	if (max < answer_temp[2])
		max = answer_temp[2];
	for (int i = 0; i < 3;i++)
		if (max == answer_temp[i])
			answer.push_back(i + 1);
		

	return answer;
}

int main(void)
{
	vector<int> answer = { 1,2,3,4,5 };
	cout << solution(answer)[0];
}