#include <iostream>
#include<string>
using namespace std;

/*
	반복문을 통해
	계속해서 중복되는 문자들을 제거하는 방식으로 진행
	- stack으로 한번에 for문을 통해서 진행또한 가능하나, 이렇게 품...
	시간초과 날뻔 했으나, 테스트케이스의 함정을 통해 역순으로 진행하니 통과
*/
int solution(string s)
{
    bool possible = false;

    string temp = s;
    while (1) {
        possible = false;
        string tmp = "";
        for (int i = temp.size()-1; i >= 0; i--)
        {
            if (tmp == "")tmp+=temp[i];
            else {
                if (tmp[tmp.size() - 1] == temp[i]) {
                    possible = true;
                    tmp.pop_back();
                }
                else
                    tmp += temp[i];
            }
        }
        temp = tmp;
        if (!possible)break;
    }

    return temp == "" ? 1 : 0;
}
