#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//���� ������ �Ǵ� ����� �ε����� �����Ͽ��� �� ����Ǵ� �Լ�
void borrow_cloth(int* arr, int n) {
	//�� ���� ���� ���� �� �ִ����� Ȯ��
	if (arr[n - 1] == 2 || arr[n + 1] == 2)
	{
		//���� �ΰ��� ���� ������ �²� ������
		if (arr[n] == 0 && arr[n - 1] == 2)
		{
			arr[n] = 1;
			arr[n - 1] = 1;
		}
		//������ �ְ� ���� ������ �²� ������.
		else if (arr[n] == 0 && arr[n + 1] == 2)
		{
			arr[n] = 1;
			arr[n + 1] = 1;
		}
	}
}


int solution(int n, vector<int> lost, vector<int> reserve) {

	int lost_count = 0;
	// �迭 ���� [ 0 |1 ~ n| 0 ]  ���� ���� �� ���� ��Ҵ� �Լ����� ������� ���Ƿ� ������ �����
	int* arr = new int[n + 2];
	arr[0] = 0; arr[n + 1] = 0;
	//������ϰ� �� ����� �ϴ� ü������ �ѹ��� �ֵ��� ����
	for (int i = 1; i <= n; i++)
		arr[i] = 1;
	//�Ҿ���� �� ���ؼ� �ѹ��� ����
	for (int i = 0; i < lost.size(); i++)
		arr[lost[i]] -= 1;
	//�����ִ� �� ���ؼ� �ϳ��� ������
	for (int i = 0; i < reserve.size(); i++)
		arr[reserve[i]] += 1;
	//����������� �⺻ 1��, ������ 0��, ���� ������ 2���� ���� ����Ʈ�� ������

	//�ֵ����� ���� ������ ����
	for (int i = 1; i <= n; i++)
	{
		//���� ��鸸 �ش� �Լ��� ��
		if (arr[i] == 0)
			borrow_cloth(arr, i);
	}
	//�����Ⱑ ���� �� �ش� �Լ����� �������� ���� ����
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
			lost_count++;
	}
	//���ο� - �������� �� = ��
	int answer = n - lost_count;
	return answer;

}