#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 필요한 개념 : 소수만들기 (에라토스테네스 체)
               vector(없어도 상관없음)
 불필요한 중복수를 전부 제거하고 서로 다른 수 집합을 만든다
해당 수들을 nC3 으로 조합하여 각각의 수가 소수인지 판별한다.
*/
bool odd[3001];
int solution(vector<int> nums) {
    int answer = 0;
    //소수인지 체크하는 for문
		for(int i = 2 ; i < 60 ; i++)
        for(int j = i+i; j <=3000; j+=i)
            odd[j] = true;
		//중복수 제거 알고리즘
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    //nC3으로 전수조사
		for(int i = 0 ; i < nums.size(); i++)
        for(int j = i+1 ; j <nums.size(); j++)
            for(int k = j+1; k<nums.size(); k++){
                int temp  = nums[i]+nums[j]+nums[k];
                if(!odd[temp])
                    answer++;
            }
    return answer;
}