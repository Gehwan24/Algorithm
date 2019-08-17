#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool esc(string a, string b)
{
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> string_num;

	for (int i = 0; i<numbers.size(); i++) {
		string_num.push_back(to_string(numbers[i]));
	}

	sort(string_num.begin(), string_num.end(), esc);

	for (auto iter = string_num.begin(); iter != string_num.end(); iter++)
		answer += *iter;

	if (answer[0] == '0')
		answer = "0";

	return answer;
}



int main(void)
{
	vector <int> hawi = { 9,96,963,97,98,972,6,10,2 };
	cout << solution(hawi)<<endl;
}


