#include <string>
#include <vector>

using namespace std;

/*
해당 문제를 푸는데 필요한 자료구조 : vector
각 수포자의 찍는 방식을 확인하고 이에 알맞는 자료구조형을 만들어 
각 답안과 비교해 정답 수 비교 한 vector count 변수 생성
해당 count 변수의 값과 같은 경우 추가, 더 큰 경우 답을 초기화하고 담는다.
*/
vector<int> solution(vector<int> answers) {
    vector<int> answer;
	vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    vector<int> count(3,0);
    
		//정답 체크
    for(int i = 0; i < answers.size(); i++){
        count[0] += one[i%one.size()] == answers[i] ? 1: 0;
        count[1] += two[i%two.size()] == answers[i] ? 1: 0;
        count[2] += three[i%three.size()] == answers[i] ? 1: 0;
    }
    int max = -1;
		
		//정답수 확인하며 가장 많은 문제를 맞춘 사람 확인하기
    for(int i = 0 ; i < 3; i++){
        if(max < count[i]){
            answer.clear();
            max = count[i];
            answer.push_back(i+1);
        }
        else if(max == count[i])
            answer.push_back(i+1);
    }
    
    return answer;
}