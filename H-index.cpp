#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	vector<int> hawi = citations;
	//오름차순으로 정렬
	sort(hawi.begin(), hawi.end()); 
	
	for (int i = 0; i < hawi.size(); i++)
	{
		// 이 인덱스 값보다 작은 애들의 수가 인덱스 값보다 작거나 같을때
		if (hawi[i]>=i)
			if (answer <= hawi.size() - i)
			{
				//만약 해당 인덱스가 남은 인덱스 수보다 작거나 같으면 해당 인덱스를 답으로 처리
				if (hawi[i] <= hawi.size() - i)
					answer = hawi[i];
				//그렇지 않을경우 남은 인덱스 수를 답으로 처리한다.
				else
					answer = hawi.size() - i;
			}
	}
	return answer;
}
//예제
int main(void)
{
	vector <int> hawi = { 3,0,6,1,2 };
	cout << solution(hawi)<<endl;
}
