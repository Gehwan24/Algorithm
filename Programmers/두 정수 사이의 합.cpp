#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	int i,j;
	if (a == b)return a;
	a > b ? i = a, j = b : i = b, j = a;
	for (j;j<=i;j++)
		answer += j;
	return answer;
}