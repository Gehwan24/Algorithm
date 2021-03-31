#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 필요한 개념 : 이분탐색
 이분탐색을 통해 h-index를 탐색 진행을 한다
 for문을 돌며 h번 이상 인용된 논문이 h편 이상 있는 최댓값 h를 반환한다.
*/
int solution(vector<int> citations) {
    int answer = 0;
    //왼쪽 오른쪽
    int left = 0; 
    int right = 10000;
    int _max = 0; //최대값
    while(left <= right){
        int mid = (left + right)/2;//현재 h index
        int less = 0;
        int more = 0;
        for(int data : citations)
        {
            if(data >= mid) more++;
            if(data < mid)less++;
        }
        //h편 이상이 h번 이상 인용했을 경우 
        if(mid <= more)_max = mid;
        
        if(mid <= more)
            left = mid + 1;
        else            
            right = mid -1;            
            
    }
    answer = _max;
    return answer;
}