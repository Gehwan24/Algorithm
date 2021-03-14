#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; i = i + 2)
		if (n%i == 0)
			if (n / i - i / 2>0)
				answer++;
	for (int i = 2; i <= n; i=i+2)
		if ((n + i / 2) % i == 0)
			if ((n + i / 2) / i - i / 2 - 1>0)
				answer++;

	return answer;
}