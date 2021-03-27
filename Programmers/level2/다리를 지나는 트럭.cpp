#include <string> 
#include <vector>
#include <iostream>
#include <queue> 

using namespace std; 

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	 int answer = 0; 
	 int sum = 0; 
	 int idx = 0; 
	 queue<int> q; 
	 while(1) 
	 { 
		 //다 돌았을 경우
		if(idx == truck_weights.size()) 
		{
			//결과값에 다리길이 더하고 while문 종료
				answer += bridge_length; 
				break;
		}
		answer++; //1초 지남
		//원하는 인덱스 값 트럭 무게 초기화
		int tmp = truck_weights[idx]; 
		//차량이 다리위에 꽉 찬 경우
		if(q.size()==bridge_length){ 
			sum -= q.front(); 
			q.pop();
		}  
		//다리에 차량을 올릴 수 있는 경우 푸쉬 
		if(sum + tmp <= weight) {
			q.push(tmp); 
			sum += tmp; 
			idx++; 
		}
		//아닐경우 무게가 0인걸 올림으로서 7 0 0 2 0 이런 느낌으로 다리를 통행하는 차량을 만듬
		else 
			q.push(0); 
	} 
	return answer; 
}
