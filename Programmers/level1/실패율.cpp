#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 필요한 개념 : 정렬 (정렬 기준 포함)
 해당 코드에서는 오름차순과 내림차순을 동시에 사용하기 때문에
 sort STL을 사용하면서 정렬 기준을 정의해주는 방법을 사용해보았다.
 
*/
//정렬기준 메소드
bool compare(pair<double,int> a,pair<double,int> b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> count(N+1,0);
    int c = 0;
    vector<pair<double,int>> fail;
    //도전자 카운팅
		for(int stage : stages)
        count[stage]++;
		// 각각 스테이지별 실패율 측정하기
    for(int i = 1 ; i <= N; i++){
        if(count[i]){
            double p = (double)count[i]/(double)(stages.size()-c);
            c+=count[i];
            fail.push_back(make_pair(p,i));
        }
        else
            fail.push_back(make_pair(0,i));
    }
		//정렬
    sort(fail.begin(),fail.end(),compare);
    //최대 실패율부터 하나씩 VECTOR에 담기
		while(!fail.empty()){
        answer.push_back(fail.back().second);
        fail.pop_back();
    }
    return answer;
}