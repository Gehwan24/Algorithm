#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//두 개의 문자열을 붙였을 때 값이 더 큰 수로 정렬하게 만들어주는 함수 
bool esc(string a, string b)
{
	//6, 10 일때 610 과 106을 비교, a+b가 더 크므로 true 반환
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> string_num;
	//int 형 인덱스들을 전부 스트링으로 변환
	for (int i = 0; i<numbers.size(); i++) {
		string_num.push_back(to_string(numbers[i]));
	}
	//위의 esc 함수를 이용하여 해당 벡터에 존재하는 문자열 인덱스 정렬
	sort(string_num.begin(), string_num.end(), esc);

	//하나의 string에 전부 더해 가장 큰수를 만듬
	for (auto iter = string_num.begin(); iter != string_num.end(); iter++)
		answer += *iter;
	//만약 0 0 0 0 = 0000일 경우를 대비하여 0으로 만들어주는 조건문 하나를 추가한다
	if (answer[0] == '0')
		answer = "0";

	//답 반환
	return answer;
}



int main(void)
{
	vector <int> hawi = { 9,96,963,97,98,972,6,10,2 };
	cout << solution(hawi)<<endl;
}


