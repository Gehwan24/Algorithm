#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
	1000000까지기 떄문에 n보다 큰 수들의 1을 세서
	1의 수가 일치하는 다음 큰 수를 반환하면 된다.
*/
int c = 0;

bool isBig(int n){
    int temp = n;
    int count = 0;
    while(temp){
        if(temp&1)count++;
        temp/=2;
    }
    if(count == c)return true;
    return false;
}
int solution(int n) {
    int temp = n;
    while(temp){
        if(temp&1)c++;
        temp/=2;
    }
    while(1){
        if(isBig(++n)){
            break;
        };
    }
    
    return n;
}
