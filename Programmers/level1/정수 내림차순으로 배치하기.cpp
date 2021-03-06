#include <string>
#include <vector>
#include <iostream>
using namespace std;

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