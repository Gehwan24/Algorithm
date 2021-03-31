#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	필요한 개념 : greedy
	가장 덩치가 나가는 사람을 기준으로 태웠을때 가장 가벼운 사람을 태울 수 
	있는지 비교하며 추가한 후 구명보트 수를 반환한다.
*/
int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int answer = people.size();
    int count = 0;
    for(int i = people.size()-1 ; i> count; i--)
    {
        if(people[i]+people[count] <= limit)
        {
            answer--;
            count++;
        }
    }
    return answer;
}