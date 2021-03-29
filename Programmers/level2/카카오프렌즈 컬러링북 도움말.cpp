#include <vector>
#include <queue>
using namespace std;

/*
	필요한 개념 : bfs
	방문한 곳인지 확인하면 최적화가 가능해진다.
	bfs를 통해 인접한 영역의 개수를 세서 최대와 영역수를 구한다
*/
int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
vector<vector<bool>> visited;
vector<vector<int>> color;
bool isRange(int i, int j, int m, int n) {
    if (i == -1 || i == m || j == -1 || j == n)
        return false;
    return true;
}
int bfs(int x, int y, int m, int n) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    int count = 1;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isRange(tmp.first + mx[i], tmp.second + my[i], m, n)) {
                if(color[tmp.first + mx[i]][tmp.second + my[i]] == color[x][y] && !visited[tmp.first + mx[i]][tmp.second + my[i]]){
                    visited[tmp.first + mx[i]][tmp.second + my[i]] = true;
                    q.push(make_pair(tmp.first + mx[i], tmp.second + my[i]));
                    count++;
                }
            }
        }
    }
    return count;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    visited.assign(m, vector<bool>(n, false));
    vector<int> answer(2, 0);

    int number_of_area = 0;
    int max_size_of_one_area = 0;
    color = picture;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && color[i][j])
            {
                int _max = bfs(i, j, m, n);
                answer[1] = answer[1] < _max ? _max : answer[1];
                answer[0]++;
            }
        }
    }
    return answer;
}