#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	int big = a;
	int	small = b;

	int tmp1 = n / 2;
	int temp = tmp1 / 2;
	int tmp2 = tmp1;


	while (big/(tmp1+1)==small/(tmp2+1))
	{
		if (big / (tmp1 + 1))
			tmp1 += temp;
		else
			tmp1 -= temp;
		if (small / (tmp2 + 1))
			tmp2 += temp;
		else
			tmp2 -= temp;
		temp /= 2;
		answer++;
	}
	
	return answer;
}