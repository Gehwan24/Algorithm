#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
 필요한 개념 : 우선순위 큐
 이용한 알고리즘 : priority_queue 이용
 우선순위 큐를 이용해 큐 안의 최솟값을 스코빌레 지수보다 높게 만들면 답이 된다.
*/
int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool is_empty = false;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i : scoville)
        pq.push(i);
    while(!pq.empty()){
        int scov = pq.top();
        pq.pop();
        if(scov < K)
        {
            answer++;
            if(pq.empty()){
                is_empty = true;
                break;
            }else{
            pq.push(scov + pq.top() * 2);
            pq.pop();
            }
        }else
            break;
    }
    if(is_empty)return -1;
    return answer;
}