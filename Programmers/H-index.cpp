#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	vector<int> hawi = citations;
	//������������ ����
	sort(hawi.begin(), hawi.end()); 
	
	for (int i = 0; i < hawi.size(); i++)
	{
		// �� �ε��� ������ ���� �ֵ��� ���� �ε��� ������ �۰ų� ������
		if (hawi[i]>=i)
			if (answer <= hawi.size() - i)
			{
				//���� �ش� �ε����� ���� �ε��� ������ �۰ų� ������ �ش� �ε����� ������ ó��
				if (hawi[i] <= hawi.size() - i)
					answer = hawi[i];
				//�׷��� ������� ���� �ε��� ���� ������ ó���Ѵ�.
				else
					answer = hawi.size() - i;
			}
	}
	return answer;
}

int main(void)
{
	vector <int> hawi = { 3,0,6,1,2 };
	cout << solution(hawi)<<endl;
}