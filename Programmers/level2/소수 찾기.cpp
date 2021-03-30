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
/* 시간초과 코드
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
*/

using namespace std;
 /*
		개선 알고리즘 : for문 반복형
		k개의 수를 제거하기 때문에 시작은
		 0~k번째에서 가장 큰 수를 찾는다.
		 이후 가장 큰 수의 인덱스부터 진행하되, 0~k번째를 
		 큰수의 인덱스 ~ k+1,큰수의 인덱스 ~ k+2....
		 으로 진행한다. 이러면 k개의 수를 제외한 가장 큰 수가 나오게된다.
		
 */

string solution(string number, int k) {
    string answer = "";
    int index = -1;
    //필요한 글자수만큼 반복하기
    for (int j = 0; j < number.length() - k; j++) {
        char max = 0;
        //앞에서 남겨야 되는 숫자 중에 제일 큰수 체크
        for (int i = index + 1; i <= k + j; i++) {
            if (max < number[i]) {
                index = i;
                max = number[i];
            }
        }
        //제일 큰수를 정답에 추가
        answer += max;
    }
    return answer;
}