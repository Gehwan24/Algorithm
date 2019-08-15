#include <cstring>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

//오름차순으로 만들기위해 필요한 비교 조건문
bool esc(int a, int b) {
	return a < b;
}
int solution(vector<int> budgets, int M) {
	int answer = 0;
	int average;
	int total = 0;
	vector<int> temp;

	//벡터 사이즈를 budgets 사이즈로 재조정
	temp.resize((int)(budgets.size()));
	
	//카운트 값을 벡터 사이즈만큼으로 설정
	int count = temp.size();

	//벡터 복사하기(맘대로 바꾸려고)
	copy(budgets.begin(), budgets.end(), temp.begin());

	//오름차순으로 정렬
	sort(temp.begin(), temp.end(), esc);
	
	//예상 기댓값 찾는 반복문 
	for (int i = 0; i < temp.size(); i++)
	{
		/*
		평균적으로 줄 수 있는 예산보다 작은 인덱스 총 합 + (아직 더하지 않은 값중 가장 작은값 * 남은 벡터 인덱스 수) < 총 예산 일때, 
		현재 인덱스는 평균적으로 줄 수 있는 예산보다 작은 인덱스의 총합에 포함되므로 남은 벡터 인덱스 수를 하나 줄이고 총 값인 total에 해당 인덱스 값을 더한다
			total : 평균적으로 줄 수 있는 예산보다 작은 인덱스 총 합

			temp[i] : 현재 인덱스 값 (이 값을 최대로 줄 수 있는 값이라 설정할 때, 조건이 성립하냐를 물어봄)
			count : 남은 벡터 인덱스 수
		*/
		if (total + temp[i] * count < M)
		{
			total += temp[i];
			count--;
		}
		//최대로 줄 수 있는 값이 해당 인덱스보다 작을 경우 평균값으로 해당 인덱스를 설정하고 반복문을 종료한다
		else
		{
			average = temp[i];
			break;
		}
	}
	//평균을 -1씩 계속 감소시키며 M값보다 작아질때까지 평균값을 조정한다.
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