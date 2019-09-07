#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool esc(int a, int b)
{
	return a > b;
}
vector<int> solution(vector<int> arr) {
	int temp = 9999;
	for (auto iter = arr.begin();iter != arr.end();iter++)
	{
		if (temp > *iter)
			temp = *iter;
	}
	arr.erase(find(arr.begin(), arr.end(), temp));
	if (arr.empty())
		arr.push_back(-1);
	
	return arr;
}

int main(void)
{
	vector<int> answer = { 4,3,2,1 };
	vector<int> arr = solution(answer);
	for (auto iter = arr.begin();iter != arr.end();iter++)
		cout << *iter << endl;
}