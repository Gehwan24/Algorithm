#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>s
using namespace std;

//���������� ����� ���� �� �Լ�
bool esc(int a, int b) {
	return a < b;
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	//�ڸ� �迭�� ��� �����ϴ� ���� ���� 
	vector<int> temp;


	for (int i = 0; i < commands.size();i++)
	{
		//���� ��ҷ� �Ҵ��� ����ŭ ������
		//commands[i][0] : �迭�� x ��° ��Һ���
		//commands[i][1] : �迭�� x ��° ��ұ���

		temp.resize(commands[i][1] - commands[i][0]+1);
		
		//temp ���Ϳ� ��Ұ� ����ֱ�
		//copy������ �ߴµ� �ȵǼ� �ݺ��� ����
		for (int k = 0; k < temp.size();k++)
			temp[k] = array[k + commands[i][0]-1];
		
		//�������� ����
		sort(temp.begin(), temp.end(), esc);	
		
		//k��° ��Ҹ� answer�� ���ҷ� �߰�
		answer.push_back(temp[commands[i][2] - 1]);
	}

	return answer;
}

int main(void)
{
	vector<int> arrays = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int> answer = solution(arrays, commands);
	for(int i = 0; i< answer.size(); i++)
		cout << answer[i] << endl;
}