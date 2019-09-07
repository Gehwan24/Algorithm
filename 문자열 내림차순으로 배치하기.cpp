#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool desc(int a, int b)
{
	return a > b;
}
string solution(string s) {
	string answer = "";
	char* temp = (char*)s.c_str();
	sort(temp, temp+s.size(), desc);
	answer = temp;
	return answer;
}

int main(void)
{
	string a = "Zbcdefg";
	cout << solution(a);
}