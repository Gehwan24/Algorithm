#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//�� ���� ���ڿ��� �ٿ��� �� ���� �� ū ���� �����ϰ� ������ִ� �Լ� 
bool esc(string a, string b)
{
	//6, 10 �϶� 610 �� 106�� ��, a+b�� �� ũ�Ƿ� true ��ȯ
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> string_num;
	//int �� �ε������� ���� ��Ʈ������ ��ȯ
	for (int i = 0; i<numbers.size(); i++) {
		string_num.push_back(to_string(numbers[i]));
	}
	//���� esc �Լ��� �̿��Ͽ� �ش� ���Ϳ� �����ϴ� ���ڿ� �ε��� ����
	sort(string_num.begin(), string_num.end(), esc);

	//�ϳ��� string�� ���� ���� ���� ū���� ����
	for (auto iter = string_num.begin(); iter != string_num.end(); iter++)
		answer += *iter;
	//���� 0 0 0 0 = 0000�� ��츦 ����Ͽ� 0���� ������ִ� ���ǹ� �ϳ��� �߰��Ѵ�
	if (answer[0] == '0')
		answer = "0";

	//�� ��ȯ
	return answer;
}



int main(void)
{
	vector <int> hawi = { 9,96,963,97,98,972,6,10,2 };
	cout << solution(hawi)<<endl;
}


