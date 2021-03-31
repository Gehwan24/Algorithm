#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
	주어진 개념 : recursive  백트래킹
	각 인덱스에 + - 한 값을 재귀적으로 함수호출하여 
	최종적으로 size와 일치할 경우 arr값에 저장해준다.
*/
vector<int> arr(2001,0);
vector<int> num;

void dfs(int start, int size, int n){
    if(start == size)
    {
        arr[n+1000]++;
        return;
    }   
    dfs(start+1,size,n+num[start]);
    dfs(start+1,size,n-num[start]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    num = numbers;
    dfs(0,numbers.size(),0);
    return arr[1000+target];
}