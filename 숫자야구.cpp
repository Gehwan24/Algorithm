#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int a[3] = { 0,0,0 };
	int one;
	int ten;
	int hund;
	int strike =0;
	int ball =0;
	bool real = true;;
	for (int j = 0; j < 1000;j++)
	{
		a[0] = j / 100;
		a[1] = (j / 10) % 10;
		a[2] = j % 10;
		if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])continue;
		if (a[0] == 0 || a[1] == 0 || a[2] == 0)continue;
		for (int i = 0; i < baseball.size();i++)
		{
			strike = 0;
			ball = 0;
			one = baseball[i][0] % 10;
			ten = (baseball[i][0] / 10) % 10;
			hund = baseball[i][0] / 100;
			if (one == a[2])strike++;
			else
				if (one == a[1] || one == a[0])
					ball++;
			if (ten == a[1])strike++;
			else
				if (ten == a[0] || ten == a[2])
					ball++;
			if (hund == a[0])strike++;
			else
				if (hund == a[1] || hund == a[2])
					ball++;
			if (strike == baseball[i][1] && ball == baseball[i][2])
				continue;
			else
			{
				real = false;
				break;
			}
		}
		if (real)
		{
			cout << a[0] << a[1] << a[2] << endl;
			answer++;
		}
		real = true;
	}
	return answer;
}

int main(void)
{
	vector<vector<int>> baseball = { {123, 1, 1},{356, 1, 0 }, { 327, 2, 0 }, { 489, 0, 1 } };
	cout << solution(baseball) << endl;
}