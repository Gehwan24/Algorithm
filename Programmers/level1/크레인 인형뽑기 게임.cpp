#include <string>
#include <vector>
using namespace std;

/*
해당 문제에서 필요한 자료구조 : stack
넣었다 뺐다 문제에서 요구하는 조건대로 구현이 가능한지 확인하는 단순한 문제였다.

배열에서 물건을 가져올 때 위에서 아래로 가기 떄문에 배열 인덱스에 주의해서 풀면 좋을거 같음
(본인은 실수함 ㅎ)
*/

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size(); // 판의 크기
    vector<int> get_items;

    //전체 로직을 구현한 부분
    for(int i = 0 ; i < moves.size(); i++)
    {
        int pos = moves[i] -1;
        
        for(int j = 0 ; j < size ; j++){
            if(board[j][pos])
            {
                int item = board[j][pos];               
                board[j][pos] = 0;
                         
                //item 확인, 비어있는 경우 그냥 넣기
                if(get_items.empty())
                    get_items.push_back(item);
                
								//item이 존재할 경우, 같으면 넣고 get_items에 담겨있는 마지막 아이템을 제거한다, 아닐경우 추가
                else{
                    if(get_items.back() == item)
                    {
                        answer+=2;
                        get_items.pop_back();
                    }
                    else
                        get_items.push_back(item);
                }
                break;
            }   
        }
    }
    return answer;
}