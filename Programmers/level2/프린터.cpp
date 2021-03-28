#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 쓸만한 자료구조 : queue,vector
 사용한 stl 구조 : sort,queue
 먼저 우선순위를 정렬해놓은 vector를 정의하고 
 queue에서 하나씩 값을 빼면서 프린터 큐 안의 최대 우선순위 값과 동일한지 확인한다
 이후 location이랑 동일한 인덱스인지 비교하고 일치할시 반복문을 종료한다.
 
*/
int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> prior_pos;
    int answer = 0;
    bool is_end = false;
    //우선순위, 위치 입력받기
    for (int i = 0; i < priorities.size(); i++)
        prior_pos.push(make_pair(priorities[i], i));

    sort(priorities.begin(), priorities.end());
    while (1) {
        //현재 기준 최대 우선순위값 가져오기
        int max_p = priorities.back();
        priorities.pop_back();
        while (!prior_pos.empty()) {
            if (prior_pos.front().first == max_p)
            {
                answer++;
                if (prior_pos.front().second == location)
                    is_end = true;
                prior_pos.pop();
                break;
            }
            else {
                pair<int, int> temp = prior_pos.front();
                prior_pos.push(temp);
                prior_pos.pop();
            }
        }
        if (is_end)break;
    }
    return answer;
}
