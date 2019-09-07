#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<int> index;
	int count = 2;
	int sum = brown + red;
	int a = (brown - 2) / 2;
	int b = 1;
	while ((a - 2)*b != red)
	{
		if ((a - 2)*b > red)
		{
			a--;
			b++;
		}	
	}
	answer.push_back(a);
	answer.push_back(b);
	return answer;
}

int main(void)
{
	int a = 2500;
	int b = 2000000;
	vector<int> i = solution(a, b);
	for (int u = 0; u < i.size();u++)
		cout << i[u] << endl;
}