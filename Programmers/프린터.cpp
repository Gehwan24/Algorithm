#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> pair_que;
	priority_queue<int> prique;

	for (int i = 0; i < priorities.size(); i++) {
		pair_que.push(make_pair(i, priorities[i]));
		prique.push(priorities[i]);//우선순위 정렬
	}

	while (!pair_que.empty()) {
		if (pair_que.front().second == prique.top())//맨앞대가리랑 같냐
		{
			if (pair_que.front().first == location) return ++answer;
			else {
				answer++;
				pair_que.pop();//출력했으니 지우고
				prique.pop(); //지움
			}
		}
		else {
			pair_que.push(pair_que.front()); //앞대가리의 우선순위와 현재 쌍의 우선순위가 다를경우
			pair_que.pop();//빼서 뒤로 집어넣고 앞대가리 삭제
		}
	}
	return answer;
}
