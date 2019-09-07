#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool desc(char a, char b)
{
	return a > b;
}
int solution(string numbers) {
	int answer = 0;
	bool real = true;
	map<int, int> number;
	map<int, int> count;
	int div;
	sort(numbers.begin(), numbers.end(), desc);
	
	cout << "numbers :" << endl;
	for (int i = 0; i < numbers.size();i++)
	{
		if (number[numbers[i]])
			number[numbers[i]]++;
		else
			number[numbers[i]]=1;
		cout << "number[" << numbers[i] << "] is : " << number[numbers[i]] << endl;
	}
	cout << "numbers :" << endl;
	int n = atoi(numbers.c_str());
	//cout << n;            // 71나옴

	int* temp = new int[n + 1];
	for (int i = 0; i < n + 1;i++)
		temp[i] = i;
	//소수 배열 만들기
	for (int i = 2; i < (n + 1) / 2;i++)
	{
		for (int j = i + i; j < n + 1;j += i)
			temp[j] = 0;
	}
	for (int i = 2; i < n + 1;i++)
	{
		
		if (temp[i])
		{
			while (temp[i] != 0)
			{
				//cout << temp[i] << endl;
				div = temp[i] % 10;
				if (count[div + 0x30])
					count[div + 0x30]++;
				else
					count[div + 0x30] = 1;
				temp[i] /= 10;
				//cout << temp[i] << endl;
				//cout << endl;
			}
			for (auto iter = count.begin();iter!=count.end();iter++)
			{
				for (auto iter2 = number.begin();iter2 != number.end();iter2++)
				{
	
					if (iter2->first == iter->first)
					{
	
						if (iter2->second < iter->second)
						{
							real = false;
							break;
						}	
						break;
					}
					if (++iter2 == number.end())
					{
						real = false;
						break;
					}
					else
						--iter2;
				}
				if (real == false)
					break;
			}
			//cout << endl << endl;
			if (real)
				answer++;
			real = true;
			count.clear();
		}
	}

	return answer;
}
int main(void)
{
	string numbers = "010203";
	cout << solution(numbers) << endl;
}