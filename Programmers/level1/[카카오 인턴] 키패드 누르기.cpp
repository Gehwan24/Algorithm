#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 조건이 꽤나 있는 문제 
 왼손에 가까운 수 1,4,7
 오른손에 가까운 수 3,6,9는 각 손으로 선택하고
 2,5,8,0은 더 가까운 위치에 존재하는 손가락이 가는 것이고,
 겨리가 동일할땐 주손잡이 손이 선택한다.
*/
pair<int,int> lpos = make_pair(3,0);
pair<int,int> rpos = make_pair(3,2);
int pos[10][2] = {{3,1},{0,0},{0,1},{0,2},
                  {1,0},{1,1},{1,2},
                  {2,0},{2,1},{2,2},
                  };
string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int number : numbers){
          int x = pos[number][0];
        int y = pos[number][1];
        if(number == 1 || number == 4 || number == 7){
            lpos.first = x;
              lpos.second = y;
              answer+="L";
            }
        else if(number == 3 || number == 6 || number == 9){
              rpos.first = x;
              rpos.second = y;  
              answer+="R";
            }
        else{
      
        int dist_l = abs(x - lpos.first)+abs(y - lpos.second);
        int dist_r = abs(x - rpos.first)+abs(y - rpos.second);
        if(dist_l == dist_r){
            if(hand == "left")
            {
              lpos.first = x;
              lpos.second = y;
              answer+="L";
            }
            else
            {
              rpos.first = x;
              rpos.second = y;  
              answer+="R";
            }
        }
        else if(dist_l < dist_r){
            lpos.first = x;
            lpos.second = y;
            answer+="L";
        }
        else{
             rpos.first = x;
             rpos.second = y;  
            answer+="R";
        }
            }
    }
    return answer;
}