#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> div;
	int big;
	int small;
	for (int i = 1;i <= n;i++)
	{
		if (n%i == 0)
		{
			div.push_back(n / i);
		}
	}
	for (int i = 0; i < div.size();i++)
		answer += div[i];
	return answer;
}