#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 필요한 개념 : 소수 만들기(에라토스테네스 체)
 이용하면 괜찮은것 : set, vector
 먼저 next_permutation을 통해 최솟값부터 
 1자리~최댓자리 수를 계속해서 set에 넣는다
 그러면 numbers로 만들 수 있는 모든 수가 정의되고
 여기서 소수임을 판단하면 구현이 가능하다.
*/
bool isOdd(int t){
    if(t <=1)return false;
    for(int i = 2; i <= sqrt(t); i++)
        if(!(t%i))
            return false;
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> each_num;
    set<int> numSet;
    //각 자리로 숫자 만들기
    for(char num: numbers)
        each_num.push_back(num-'0');
    sort(each_num.begin(),each_num.end());
    do{
        int total = 0;
        for(int i = 0 ; i < each_num.size(); i++){
            total = total*10 + each_num[i];
            numSet.insert(total);
        }
    }while(next_permutation(each_num.begin(),each_num.end()));
    for(auto iter = numSet.begin();iter!=numSet.end();iter++)
        if(isOdd(*iter)){
            answer++;
        }
    return answer;
}