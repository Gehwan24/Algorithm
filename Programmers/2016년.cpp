#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int sum = 0;
	int result = 5; // 금요일 나타냄
	string day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int cal_day[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < a - 1; i++)
		sum += cal_day[i];
	sum += b - 1;
	sum %= 7;
	result = (result + sum) % 7;
	answer += day[result];

	return answer;

}
