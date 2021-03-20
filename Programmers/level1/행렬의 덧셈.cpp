#include <string>
#include <vector>

using namespace std;

/* 
  각 행렬끼리 덧셈을 해준다
*/
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    for(int i = 0 ; i < arr1.size(); i++)
        for(int j = 0 ; j  <arr1[i].size(); j++)
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
    return answer;
}