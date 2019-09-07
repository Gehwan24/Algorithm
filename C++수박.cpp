#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	int rem = n / 2;
	int div = n % 2;
	for (int i = 0; i < rem;i++)
		answer += "¼ö¹Ú";
	if (div)
		answer += "¼ö";
	return answer;
}