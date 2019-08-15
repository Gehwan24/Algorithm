#include <cstring>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

//������������ ��������� �ʿ��� �� ���ǹ�
bool esc(int a, int b) {
	return a < b;
}
int solution(vector<int> budgets, int M) {
	int answer = 0;
	int average;
	int total = 0;
	vector<int> temp;

	//���� ����� budgets ������� ������
	temp.resize((int)(budgets.size()));
	
	//ī��Ʈ ���� ���� �����ŭ���� ����
	int count = temp.size();

	//���� �����ϱ�(����� �ٲٷ���)
	copy(budgets.begin(), budgets.end(), temp.begin());

	//������������ ����
	sort(temp.begin(), temp.end(), esc);
	
	//���� ��� ã�� �ݺ��� 
	for (int i = 0; i < temp.size(); i++)
	{
		/*
		��������� �� �� �ִ� ���꺸�� ���� �ε��� �� �� + (���� ������ ���� ���� ���� ������ * ���� ���� �ε��� ��) < �� ���� �϶�, 
		���� �ε����� ��������� �� �� �ִ� ���꺸�� ���� �ε����� ���տ� ���ԵǹǷ� ���� ���� �ε��� ���� �ϳ� ���̰� �� ���� total�� �ش� �ε��� ���� ���Ѵ�
			total : ��������� �� �� �ִ� ���꺸�� ���� �ε��� �� ��

			temp[i] : ���� �ε��� �� (�� ���� �ִ�� �� �� �ִ� ���̶� ������ ��, ������ �����ϳĸ� ���)
			count : ���� ���� �ε��� ��
		*/
		if (total + temp[i] * count < M)
		{
			total += temp[i];
			count--;
		}
		//�ִ�� �� �� �ִ� ���� �ش� �ε������� ���� ��� ��հ����� �ش� �ε����� �����ϰ� �ݺ����� �����Ѵ�
		else
		{
			average = temp[i];
			break;
		}
	}
	//����� -1�� ��� ���ҽ�Ű�� M������ �۾��������� ��հ��� �����Ѵ�.
	while (total + (average)*count>M) {
		average--;
	}
	return average;
}

int main(void)
{
	vector <int> a = { 120,110,140,150 };
	int m = 485;
	cout << solution(a, 485) << endl;
}