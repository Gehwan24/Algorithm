#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

/*
	처음 구현 : bfs 
	두번쨰 구현 : priority _queue를 이용한 구현
	생각해보니 도착지점 n 부터 1까지 나누면서 역으로 가는게 더 낫지 않을까
	나머지 1일경우에 빼주기를 진행하면 더 쉬울거 같다는 생각을 하게 됐음
	
*/
int solution(int n)
{
    int count = 0;
  while(n){
      count += n%2 ? 1 : 0;
      n/=2;
  }
    return count;
}
