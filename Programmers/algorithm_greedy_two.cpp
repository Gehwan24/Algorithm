#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//옷을 빌려야 되는 사람의 인덱스에 접근하였을 떄 진행되는 함수
void borrow_cloth(int* arr, int n) {
	//양 옆에 옷을 빌릴 수 있는지를 확인
	if (arr[n - 1] == 2 || arr[n + 1] == 2)
	{
		//왼쪽 인간이 옷이 있으면 걔꺼 빌리고
		if (arr[n] == 0 && arr[n - 1] == 2)
		{
			arr[n] = 1;
			arr[n - 1] = 1;
		}
		//오른쪽 애가 옷이 있으면 걔꺼 빌린다.
		else if (arr[n] == 0 && arr[n + 1] == 2)
		{
			arr[n] = 1;
			arr[n + 1] = 1;
		}
	}
}


int solution(int n, vector<int> lost, vector<int> reserve) {

	int lost_count = 0;
	// 배열 선언 [ 0 |1 ~ n| 0 ]  으로 선언 양 끝의 요소는 함수식을 만드려고 임의로 설정한 빈공간
	int* arr = new int[n + 2];
	arr[0] = 0; arr[n + 1] = 0;
	//기모찌하게 각 놈들이 일단 체육복이 한벌씩 있도록 설정
	for (int i = 1; i <= n; i++)
		arr[i] = 1;
	//잃어버린 놈에 한해서 한벌씩 뺏음
	for (int i = 0; i < lost.size(); i++)
		arr[lost[i]] -= 1;
	//여분있는 놈에 한해서 하나씩 더해줌
	for (int i = 0; i < reserve.size(); i++)
		arr[reserve[i]] += 1;
	//여기까지오면 기본 1벌, 없으면 0벌, 여분 있으면 2벌을 가진 리스트를 생성함

	//애들한테 서로 빌리는 과정
	for (int i = 1; i <= n; i++)
	{
		//없는 놈들만 해당 함수에 들어감
		if (arr[i] == 0)
			borrow_cloth(arr, i);
	}
	//빌리기가 끝난 후 해당 함수에서 못빌린놈 숫자 세기
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
			lost_count++;
	}
	//총인원 - 못빌린놈 수 = 답
	int answer = n - lost_count;
	return answer;

}