#include <string>
#include <queue>
using namespace std;
/*
	알면 좋은 개념 : visited를 통한 시뮬레이션
	현재에서 간 방향 -> true
		       온 방향 -> true 설정을 통해 왔던 경로를 체킹해둠
	
	이후 해당 방문된 곳을 또 방문할 경우는 무시하고 
	방문하지 않은 경로를 갈 경우 answer증가시키기
*/
int mx[] = {-1,0,1,0};
int my[] = {0,-1,0,1};
bool arr[11][11][4]; // x,y좌표 , 0 1 2 3 온 방향

bool check(int x, int y){
    if(x == -1 || y == -1 || x == 11 || y == 11)return false;
    return true;
}
int solution(string dirs) {
    int answer = 0;
    pair<int,int> pos = make_pair(5,5);
    
    for(char dir : dirs){
        int cur = -1;
        switch(dir){
            case 'U' :
                cur = 0;                
                break;
            case 'L' :
                cur = 1;
                break;
            case 'D' :
                cur = 2;
                break;
            case 'R' :
                cur = 3;
                break;
        }
        if(check(pos.first + mx[cur],pos.second + my[cur])){
            if(!arr[pos.first][pos.second][cur])answer++;            

            arr[pos.first][pos.second][cur] = true;
            arr[pos.first + mx[cur]][pos.second+my[cur]][(cur+2)%4] = true;
            pos.first +=mx[cur];
            pos.second += my[cur];
        }
    }
    return answer;
}