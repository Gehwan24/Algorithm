#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
/*
	에라토스테네스 체 이용하여 소수 찾기
*/

int arr[1000001];

int solution(int n) {
    int answer = 0;
    for(int i = 2; i<=sqrt(n) ; i++)
        for(int j = i+i; j <= n; j+=i)
            arr[j]++;
    for(int i = 2; i <= n ; i++)
    {
        if(!arr[i])
            answer++;
    }
    return answer;
}