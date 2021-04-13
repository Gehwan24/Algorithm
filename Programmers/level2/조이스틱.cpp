#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
	알면 좋은 개념 : greedy 
	먼저, 각 글자별로 최소한으로 움직여서 만들 수 있는 횟수가 담긴 벡터 c를 만듦
	이후 반복문을 진행하면서 아직 방문하지 않고, 조작을 해야하는 글자를 왼쪽,오른쪽 방향으로
	진행한다.
	가장 인접한 위치에 있는 숫자를 cur로 변경해주는 것을 계속해서 반복하며
	전부 방문했거나, 더이상 변경할 것이 없을 경우에 종료한다.
*/
int solution(string name) {
    vector<int> c(name.size(),0);
    vector<bool> visit(name.size(),false);
    for(int i = 0 ; i < name.size(); i++){
        c[i] = name[i]-'A' < 'Z'-name[i] ? name[i]-'A' : 'Z'-name[i]+1;
    }
    int answer = 0;
    int cur = 0;
    int count = 0;
    while(1){
        answer+=c[cur];
        visit[cur] = true;
        c[cur] = 0;
        count++;
        int left = -1,lc = 0;
        int right = -1,rc = 0;
        int temp_count = 0;
        while(temp_count <= name.size())
        {
            int tmp = ((cur-temp_count)+name.size())%name.size();
            if(c[tmp] && !visit[tmp]){
                left = tmp;
                break;
            }
            lc++;
            temp_count++;
        }        
        temp_count = 0;
        while(temp_count <= name.size())
        {
            int tmp = (cur+temp_count)%name.size();
            if(c[tmp] && !visit[tmp]){
                right = tmp;
                break;
            }
            rc++;
            temp_count++;
        }        
        //다 먹었는지 확인
        if(left == -1)break;
        else{
             cur = lc < rc ? left : right;
                answer += lc < rc ? lc : rc;
            }
        
    }
    return answer;
}