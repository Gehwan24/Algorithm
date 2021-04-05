#include <iostream>

/*	
	알면 좋은 개념 : 이분탐색, 재귀
	이분탐색과 재귀를 이용해 반씩 쪼개가며 탐색을 진행하도록 구현했다
	반으로 쪼갰을 때, 각각 다른 영역에 존재한다면 대진은 그 다음에 이루어지기 때문에
	해당 size(남은 크기)로 answer를 반환할 수 있다(size = 2^n승이니깐)
*/
using namespace std;
int cur_a = -1;
int cur_b = -1;

int find_answer(int a,int b, int start,int end){
    int tmp = (start+end)/2;
    int c = 0;
    if(a <= tmp && tmp < b)
    {
        int s = (end-start)/2;
        while(s){
            s/=2;
            c++;
        }
        return c;
    }
    else{
        if(b <= tmp)
            return find_answer(a,b,start,tmp);
        else
            return find_answer(a,b,tmp,end);
    }
    return c;
}

int solution(int n, int a, int b)
{
    cur_a = a > b ? b : a;
    cur_b = a > b ? a : b;
    int answer = find_answer(cur_a,cur_b,0,n);
    return answer;
}