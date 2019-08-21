#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//�������� �����Լ�
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
	//�ε�����ġ�� ��Ÿ���� ���� �����ϴ� ���� temp_index
	vector<int> temp_index;
	for (int i = 0; i < plays.size();i++)
		temp_index.push_back(i);
	
	for (int i = 0;i < temp_index.size()-1;i++)
	{
		for(int j = 0; j<temp_index.size()-1;j++)
			//������������ �� ����
			//�ε��� �� ���ڿ��� ���ÿ� �������ش�
			if (plays[j] < plays[j+1])
			{
				//�÷���Ƚ�� ����
				temp = plays[j];
				plays[j] = plays[j+1];
				plays[j+1] = temp;
				//�÷��� Ƚ�� �ε��� ����
				temp = temp_index[j];
				temp_index[j] = temp_index[j + 1];
				temp_index[j + 1] = temp;
				//�帣 ���ڿ� ����
				temp_str = genres[j];
				genres[j] = genres[j + 1];
				genres[j + 1] = temp_str;
				temp_str = "";
			}
	}
	//�帣���� ���Ϳ� �߰����ָ�, �� �帣�� �÷��� Ƚ�� ������ ���Ѵ�
	for (int i = 0; i < genres.size();i++)
	{
		hawi[genres[i]].push_back(temp_index[i]);
		if (sum[genres[i]])
			sum[genres[i]] += plays[i];
		else
			sum[genres[i]] = plays[i];
	}
	cout << "sum :" << endl;
	//������ ����� �Ǿ����� ����غα�
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

	//�÷��̺� �� ���� �ϳ��� �ִ´�
	for (auto iter = sum.begin();iter!=sum.end();iter++)
		answer_sum.push_back(iter->second);
	//������������ �����Ѵ�
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
			//���� ū �� �÷��� ���� ���� �帣�� ��� ������ ���ǹ��� �� 
			if (iter->second == answer_sum[i])
			{
				for (auto iter2 = hawi.begin();iter2 != hawi.end();iter2++)
				{
					//�帣�� �����ϰ� �帣�� ���� �ε����� �� �̻��� ��� �ΰ��� ���� �信 ����
					if (iter->first.compare(iter2->first) == 0&&iter2->second.size()>=2)
					{					
						answer.push_back(iter2->second[0]);
						answer.push_back(iter2->second[1]);
						break;
					}
					//�帣�� �����ϰ� �帣�� ���� �ε����� �Ѱ��� ��� �Ѱ��� ���� �信 ����
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