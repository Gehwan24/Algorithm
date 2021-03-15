#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
	필요한 자료구조 : vector
	알아야 할 개념 : greedy 
	체육복이 없는 친구가 옆자리 아이걸 빌린다는 개념으로 진행 
	왼쪽아이부터 오른쪽, 왼쪽 순서대로 빌린다
	오른쪽 아이부터 오른쪽, 왼쪽 순서대로 빌린다 
	두 가지를 고려하여 진행, 두 가지를 진행해 더 많은 체육복을 입은 학생수를 찾아 해당 값 반환
*/
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0,left_c = 0, right_c = 0;
    vector<int> left(n,1);
    vector<int> right(n,1);
    
    for(int pos : lost){
        left[pos-1]--;
        right[pos-1]--;
    }
     
    for(int pos : reserve){
        left[pos-1]++;
        right[pos-1]++;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        left_c += left[i] ?  1: 0;
        right_c += right_c ? 1 : 0;
    }
    
    for(int i = 0 ; i < n-1; i++){
        if(!left[i]){
            if(left[i+1] > 1)
            {
                left[i]++;
                left[i+1]--;
                left_c++;
            }
            else if(i > 0 && left[i-1] > 1){
                left[i]++;
                left[i-1]--;
                left_c++;
            }
        }
        int pos = n-i-1;
        if(!right[pos]){
            if(pos > 0 && right[pos-1] > 1)
            {
                right[pos]++;
                right[pos-1]--;
                right_c++;
            }
            else if(right[pos+1] > 1){
                right[pos]++;
                right[pos+1]--;
                right_c++;
            }
        }
    }
   
    answer = left_c > right_c ? left_c : right_c; 
    return answer;
}