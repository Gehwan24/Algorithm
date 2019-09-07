#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
문제 : 124 문제
3의 제곱승가지로 각 자리수마다 경우의수가 존재함 
ex) 40 = 3 + 9 + 27 + 1 4 4 1111 -> 40
	10 = 3 + 7 -> 3+4 -> 3+1 41
	13 = 111

문제 해결 방법 : 
 큰 수 n 을 3의 제곱승을 계속 뺴주는 형식?
 100 = 3 + 9 + 27 + 61(4444)  -> 3 + 9 + 27 + 22(11444) ->3+9+10 (12144)->3+7 ->(12214)->(12241) 
*/
string solution(int n) {
	string answer = "";
	int tmp;
	while (n > 0)
	{
		tmp = n % 3;
		if (tmp == 0) n = (n / 3) - 1;//나머지가 없을때는 몫에서 1 빼준다 
		else n /= 3;
		answer = "412"[tmp] + answer;
	}
	return answer;
}