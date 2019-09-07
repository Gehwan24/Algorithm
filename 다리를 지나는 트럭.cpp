#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;//전체가 다리를 건널때까지의 총 시간
	int bridge_weight = 0;//다리위에 올라가 있는 모든 차의 무게
	vector<int> truck_count;
	for (int i = 0; i < truck_weights.size();i++)
	{
		cout << "i is " << i<<endl;
		answer++;
		cout << answer << endl;
		if (!truck_count.empty())
		{
			for (int j = 0; j < truck_count.size();j++)
			{
				truck_count[j] += 1;
				cout << "truck_count[" << "j" << "] is : " << j << endl;
				if (truck_count[j] <= bridge_length)
				{
					cout << "yeah" << endl;
					if (truck_count[j] == bridge_length)
					{
						bridge_weight -= truck_weights[j];
						cout << " total is : " << bridge_weight << endl;
						continue;
					}
				}
			}
		}
		if (truck_weights[i] + bridge_weight <= weight)
		{
			bridge_weight += truck_weights[i];
			cout << "input : " << truck_weights[i] << " total is : " << bridge_weight << endl;
			truck_count.push_back(0);
		}
		else {
			i--;
		}
	}
	cout << "answer is : " << answer << endl;
	cout << "gimochi" << endl;
	while (1)
	{
		if (truck_count[truck_count.size() - 1] == bridge_length)
			break;
		answer++;
		for (int i =0 ; i < truck_count.size(); i++)
		{
			if (truck_count[i] >= bridge_length)
				continue;
			else
				truck_count[i]+=1;
		}
	}
	cout << "answer is : " << answer << endl;
	return answer;
}

int main(void)
{
	int a = 2;
	int b = 10;
	vector<int> ab = { 7,4,5,6 };
	int an =  solution(a, b, ab);
	cout << "answer is : " << an << endl;
}