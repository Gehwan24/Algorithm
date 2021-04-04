#include<vector>
#include <queue> 
#include <algorithm>

using namespace std;

/*
	알면 좋은 알고리즘 : bfs , priority_queue
	
	최단 경로를 알고싶은 것이기 때문에 출발지에서 (x,y)로 갈 수 있는 최단 거리를
	계속해서 priority_queue에 입력하며 최종 경로에 도착했을때의 count 값을 반환해준다.
	없을 경우 -1
*/
vector<vector<bool>> visited;
int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    visited.assign(maps.size(), vector<bool>(maps[0].size(), false));// 방문 정의
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push(make_pair(1, make_pair(0, 0)));
    visited[0][0] = true;
    
    while (!q.empty()) {
        pair<int, int> t = q.top().second;
        int count = q.top().first;
        q.pop();
        if (t.first == maps.size() - 1 && t.second == maps[0].size() - 1) {
                answer = count;
                break;
        }
        for (int k = 0; k < 4; k++) {
            int tx = t.first + mx[k];
            int ty = t.second + my[k];
            if (tx == -1 || tx == maps.size()|| ty == -1 || ty == maps[0].size())
                continue;
            else
            {
                if (!visited[tx][ty] && maps[tx][ty]){
                    visited[tx][ty] = true;
                    q.push(make_pair(count + 1, make_pair(tx, ty)));
                }
            }
        }
    }
    if(answer == 0)answer = -1;
    return answer;
}