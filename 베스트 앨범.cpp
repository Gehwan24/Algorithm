#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//내림차순 정렬함수
bool swap(int a, int b)
{
	return a < b;
}
vector<int> solution(vector<string> genres, vector<int> plays) {

	int temp = 0;
	string temp_str = "";
	vector<int> answer;
	vector<int> answer_sum;
	map <string, vector<int>> hawi;
	map <string, int> sum;
	//인덱스위치를 나타내는 값을 저장하는 벡터 temp_index
	vector<int> temp_index;
	for (int i = 0; i < plays.size();i++)
		temp_index.push_back(i);
	
	for (int i = 0;i < temp_index.size()-1;i++)
	{
		for(int j = 0; j<temp_index.size()-1;j++)
			//내림차순으로 수 정렬
			//인덱스 및 문자열도 동시에 정렬해준다
			if (plays[j] < plays[j+1])
			{
				//플레이횟수 정렬
				temp = plays[j];
				plays[j] = plays[j+1];
				plays[j+1] = temp;
				//플레이 횟수 인덱스 정렬
				temp = temp_index[j];
				temp_index[j] = temp_index[j + 1];
				temp_index[j + 1] = temp;
				//장르 문자열 정렬
				temp_str = genres[j];
				genres[j] = genres[j + 1];
				genres[j + 1] = temp_str;
				temp_str = "";
			}
	}
	//장르별로 벡터에 추가해주며, 각 장르별 플레이 횟수 총합을 구한다
	for (int i = 0; i < genres.size();i++)
	{
		hawi[genres[i]].push_back(temp_index[i]);
		if (sum[genres[i]])
			sum[genres[i]] += plays[i];
		else
			sum[genres[i]] = plays[i];
	}
	cout << "sum :" << endl;
	//정렬이 제대로 되었는지 출력해부기
	for (auto iter = sum.begin();iter != sum.end();iter++)
		cout << iter->second << " ";
	cout << endl;
	for (auto iter2 = hawi.begin();iter2 != hawi.end();iter2++)
	{
		cout << iter2->first << endl;
		for (auto iter = iter2->second.begin(); iter != iter2->second.end();iter++)
			cout << *iter << " ";
		cout << endl;
	}

	//플레이별 총 합을 하나씩 넣는다
	for (auto iter = sum.begin();iter!=sum.end();iter++)
		answer_sum.push_back(iter->second);
	//오름차순으로 정렬한다
	sort(answer_sum.begin(), answer_sum.end());
	cout << "answer_sum" << endl;
	for (int i = 0; i < answer_sum.size();i++)
		cout << answer_sum[i] << " ";
	cout << endl;
	cout << "answer_sum.size() : " << answer_sum.size() << endl;
	for (int i = answer_sum.size() - 1;i >= 0;i--)
	{
		for (auto iter = sum.begin();iter != sum.end(); iter++)
		{
			//가장 큰 총 플레이 값을 가진 장르일 경우 다음의 조건문에 들어감 
			if (iter->second == answer_sum[i])
			{
				for (auto iter2 = hawi.begin();iter2 != hawi.end();iter2++)
				{
					//장르가 동일하고 장르에 대한 인덱스가 둘 이상일 경우 두개의 값을 답에 넣음
					if (iter->first.compare(iter2->first) == 0&&iter2->second.size()>=2)
					{					
						answer.push_back(iter2->second[0]);
						answer.push_back(iter2->second[1]);
						break;
					}
					//장르가 동일하고 장르에 대한 인덱스가 한개일 경우 한개의 값을 답에 넣음
					else if (iter->first.compare(iter2->first) == 0 && iter2->second.size() == 1)
					{
						answer.push_back(iter2->second[0]);
						break;
					}
				}
			}
		}
	}
	return answer;
}
int main(void)
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" ,"gimochi","gimochi","hawi","pop"};
	vector<int> plays = { 500,600,150,800,2500,3000,2300,340,2530}; 
	vector<int> answer = solution(genres, plays);
	for (int i = 0; i < answer.size();i++)
		cout << answer[i] << " ";
}