#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
int solution(int n) {
	int answer = 0;
	bool is_real = true;
	vector<int> odd;
	odd.push_back(2);
	for (int i = 2;i <= n;i++)
	{
		if (i % 2 == 0)continue;
		for (auto iter = odd.begin();iter != odd.end();iter++)
		{
			if (i%*iter == 0)
			{
				is_real = false;
				break;
			}
		}
		if (is_real)odd.push_back(i);
		is_real = true;
	}
	answer = odd.size();
	return answer;
}
*/
int solution(int n) {
	int answer = 0;
	int* temp = new int[n + 1];
	for (int i = 0; i < n + 1;i++)
		temp[i] = i;
	for (int i = 2; i < (n+1)/2;i++)
	{
		for (int j = i+i; j < n + 1;j += i)
		{
			temp[j] = 0;
			cout << "j is :" << j << "  i is : " << i <<temp[j]<< endl;
		}

	}
	for (int i = 2; i < n + 1;i++)
		if (temp[i] != 0) {
			cout << "temp[" << i << "] is :" << temp[i] << endl;
			answer++;
		}
	return answer;
}
int main(void)
{
	cout << solution(3) << endl;
}