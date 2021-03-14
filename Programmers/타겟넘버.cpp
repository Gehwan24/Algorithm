#include <string>
#include <vector>

using namespace std;
int answer = 0;
void bfs(vector<int> numbers, int a, int target, int result)
{
	if (result == target)
	{
		answer++;
		return;
	}
	if (a == numbers.size())
	{
		return;
	}
	if (result + numbers[a]>target)
		bfs(numbers, a + 1, target, result);
	else
		bfs(numbers, a + 1, target, result + numbers[a]);
	bfs(numbers, a + 1, target, result - numbers[a]);
}
int solution(vector<int> numbers, int target) {

	bfs(numbers, 0, target, 0);
	return answer;
}