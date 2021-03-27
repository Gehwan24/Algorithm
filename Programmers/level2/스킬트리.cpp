#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define MAX 999
/*
 해당 문제에 팔요한 개념 : 각 인덱스를 어떻게 정의할 것인지가 중요할듯..?
 skill에 포함되는 선행스킬들은 무조건 이미 이용해야되기 때문에 해당 부분을 이용
 각 스킬에서 선행스킬이 필요한 스킬들의 순서를 배열에 저장하고
 저장된 순서에 알맞게 스킬트리가 진행되었는지 반복문을 통해 검사 진행
*/
//선행 스킬 순서
vector<int> skill_pos(26,MAX);

int solution(string skill, vector<string> skill_trees) {
    for(int i = 0 ; i < skill.size(); i++)
        skill_pos[skill[i]-'A'] = i; //각 스킬별 트리 순서
    int answer = 0;
    
    for(int i = 0 ; i < skill_trees.size(); i++){
        int pos = -1;
        bool is_right = true;
        for(int j = 0 ; j < skill_trees[i].size(); j++){
            if(skill_pos[skill_trees[i][j]-'A'] != MAX){
                if(pos+1 == skill_pos[skill_trees[i][j]-'A'])
                    pos = skill_pos[skill_trees[i][j]-'A'];
                else{
                    is_right = false;
                    break;     
                }
            }
        }
        if(is_right)answer++;
    }
    return answer;
}