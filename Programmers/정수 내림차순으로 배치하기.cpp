#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool esc(int a, int b)
{
	return a> b;
}
long long solution(long long n) {
	long long answer = 0;
	vector<int> temp;
	long long tmp = n;
	while (tmp != 0)
	{
		temp.push_back(tmp%10);
		tmp /= 10;
	}
	sort(temp.begin(), temp.end(), esc);
	for (auto iter = temp.begin();iter != temp.end();iter++)
	{
		answer *= 10;
		answer += *iter;
	}
	return answer;
}
int main(void)
{
	cout << solution(118372) << endl;
}