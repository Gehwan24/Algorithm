#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	char* temp = (char*)phone_number.c_str();
	for (int i = phone_number.size() - 5;i >= 0;i--)
		temp[i] = '*';
	answer = temp;
	return answer;
}