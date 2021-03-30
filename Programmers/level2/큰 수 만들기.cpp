#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
	필요한 개념 : 조합
	알면 좋은 알고리즘 : next_permutation
	nCr로 몇 개의 수를 제거하는 조합을 만들어서
	next_permutation을 진행하면 가장 큰 수를 만들 수 있음
*/
string solution(string number, int k) {
    string answer = "0";
    vector<int> num(number.size(), 1);
    for (int i = 0; i < k;i++)
        num[i] = 0;
    do
    {
        string temp_num = "";
        for (int i = 0; i < num.size(); i++) {
            if (num[i])
                temp_num += number[i];
        }
        if (answer < temp_num)answer = temp_num;
       
    } while (next_permutation(num.begin(), num.end()));
    return answer;
}