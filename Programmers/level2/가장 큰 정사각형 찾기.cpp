#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
	dp를 생각하면 쉬울듯 하다
	정사각형이 되기 위해서는 
	옆 위 대각선 모두가 1로 체크가 되어져 있어야만 하기 떄문에
	이를 이용해서 (옆 위 대각선)의 최솟값을 구하고 이와 현재의 위치값을 더해주면 
	정사각형의 한 변의 길이가 나온다
	다만, 현재 위치가 연결이 가능할 경우에만 정사각형의 크기가 커지기 때문에
	arr[i][j]가 0보다 클 경우에만 비교를 진행한다.
*/
int solution(vector<vector<int>> board)
{
    vector<vector<int>> arr(board.size()+1,vector<int>(board[0].size()+1,0));
    for(int i = 1; i <arr.size(); i++)
        for(int j = 1; j< arr[i].size(); j++)
            arr[i][j] = board[i-1][j-1];
    int answer = -1;
    for(int i = 1 ; i<arr.size(); i++)
        for(int j = 1 ; j < arr[i].size(); j++){
            if(arr[i][j])
                arr[i][j] = min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]})+arr[i][j];
        answer = answer < arr[i][j] ? arr[i][j] : answer;        
    }

    return answer*answer;
}