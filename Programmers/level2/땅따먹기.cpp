#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	필요한 개념 : dp
	아래로 내려가면서 먹을 수 있는 최댓값을 배열에 저장한다
	dp를 통해 최댓값을 계속해서 구해나간다.
*/
int solution(vector<vector<int> > land)
{
    vector<vector<int>> m(land.size()+1,vector<int>(4,0));
    for(int i = 1; i< m.size(); i++){
        for(int j = 0 ; j < 4; j++)
        {
            for(int k = 0; k< 4; k++)
                if(j!=k){
                    if(m[i][j] < land[i-1][j] + m[i-1][k])
                        m[i][j] = land[i-1][j] + m[i-1][k];
                }
        }
    }
    int _max= -1;
    for(int i = 0 ; i < 4; i++)
        _max = m[land.size()][i] > _max ? m[land.size()][i] : _max;
    return _max;
}