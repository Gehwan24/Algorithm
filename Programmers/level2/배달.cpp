#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
	 난 멍청하다...
	 다익스트라 까먹어서 엄청 헤맨 문제...
	 필요한 개념 : 다익스트라
	 or bfs도 가능할듯?

	 각 지점의 최단거리를 찾아 K보다 작은 개수를 센다
	
*/

vector<int> dist;
vector<bool> visited;
vector<vector<int>> g;

int find(int u){
    int idx = -1;
    int _min = 987654321;
    for(int i = 1; i<dist.size();i++){
        if(!visited[i] && dist[i]!=987654321){
            if(_min > dist[i]){
                _min = dist[i];
                idx = i;
            } 
        }
    }
    return idx;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.assign(N+1,987654321);
    visited.assign(N+1,false);
    g.assign(N+1,vector<int>(N+1,987654321));

    for(int i = 0 ; i < road.size(); i++){
        g[road[i][0]][road[i][1]] = min(g[road[i][0]][road[i][1]],road[i][2]);
        g[road[i][1]][road[i][0]] = min(g[road[i][1]][road[i][0]],road[i][2]);
    }
    visited[1] = true;
    dist[1] = 0;
    for(int i = 1; i<dist.size(); i++)
        if(g[1][i] != 987654321)
            dist[i] = g[1][i];
    
    int idx = find(1);
    while(idx!= -1){
        visited[idx] = true;
        for(int i = 1; i< dist.size(); i++){
            if(g[idx][i]){
                dist[i] = min(dist[idx] + g[idx][i],dist[i]);
            }
        }
        idx = find(idx);
    }
    for(int i = 1; i < dist.size(); i++){
        if(dist[i] <= K)
            answer++;
        }

    return answer;
}