#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int j = 0;
	int count = 0;
	string temp = number;
	vector<int> position;
		while(1){
			if (j + 1 == temp.size())break;
			
			if (temp[j] < temp[j + 1])
			{
				if(j==0)
					temp.erase(temp.begin());
				else
					temp.erase(temp.begin()+j);
				count++;
				j = 0;
				if (count == k)break;
			}
			else
				j++;		
		}

	if (count < k)
	{
		for (int i = 0;i < temp.size() - (k - count);i++)
			answer += temp[i];
	}
	else
	answer = temp;
	return answer;
}

int main(void)
{
	string a = "10000";
	cout << solution(a, 2) << endl;
}