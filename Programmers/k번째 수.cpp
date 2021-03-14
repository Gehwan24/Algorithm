#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>s
using namespace std;

//오름차순을 만들기 위한 비교 함수
bool esc(int a, int b) {
	return a < b;
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	//자른 배열을 담아 정렬하는 벡터 변수 
	vector<int> temp;


	for (int i = 0; i < commands.size();i++)
	{
		//벡터 요소로 할당할 수만큼 재조정
		//commands[i][0] : 배열의 x 번째 요소부터
		//commands[i][1] : 배열의 x 번째 요소까지

		temp.resize(commands[i][1] - commands[i][0]+1);
		
		//temp 벡터에 요소값 집어넣기
		//copy쓰려고 했는데 안되서 반복문 돌림
		for (int k = 0; k < temp.size();k++)
			temp[k] = array[k + commands[i][0]-1];
		
		//오름차순 정렬
		sort(temp.begin(), temp.end(), esc);	
		
		//k번째 요소를 answer의 원소로 추가
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