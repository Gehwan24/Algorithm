#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
���� : 124 ����
3�� �����°����� �� �ڸ������� ����Ǽ��� ������ 
ex) 40 = 3 + 9 + 27 + 1 4 4 1111 -> 40
	10 = 3 + 7 -> 3+4 -> 3+1 41
	13 = 111

���� �ذ� ��� : 
 ū �� n �� 3�� �������� ��� ���ִ� ����?
 100 = 3 + 9 + 27 + 61(4444)  -> 3 + 9 + 27 + 22(11444) ->3+9+10 (12144)->3+7 ->(12214)->(12241) 
*/
string solution(int n) {
	string answer = "";
	int tmp;
	while (n > 0)
	{
		tmp = n % 3;
		if (tmp == 0) n = (n / 3) - 1;//�������� �������� �򿡼� 1 ���ش� 
		else n /= 3;
		answer = "412"[tmp] + answer;
	}
	return answer;
}