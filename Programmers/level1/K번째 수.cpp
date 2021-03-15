#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
	해당 문제에서 필요한 자료구조 : vector
	알면 좋을만한 STL : assign, sort
	정렬과 할당을 통해 간결하게 구현 가능
*/
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int i = 0 ; i < commands.size(); i++){
        temp.assign(array.begin()+commands[i][0]-1,array.begin()+commands[i][1]);
        sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}