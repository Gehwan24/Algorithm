#include <cmath>
#include <iostream>
using namespace std;
/*
 이게 double형 소수점에서 오차가 발생해서 문제가 발생한거 같다
 1억을 기준으로 double형을 사용하면 오차가 나중에 0.00000000001에서 차이가 발생함
 그래서 큰 수에서 틀리는거 같음

 -> 대처 long double, gcd를 통해 수를 나누어 gcd 범위에서 제거되는 사각형의 수를 계산하고
 그 수만큼 곱해줘 정상 사각형에서 제거하는 방식으로 구현을 진행하였다.
*/
int gcd (int w, int h){
    if(h == 0)return w;
    else return gcd(h,w%h);
}
long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    int _max = w > h ? w : h;
    int _min = w < h ? w : h;
    long double left = (long double)_max / (long double)_min;
    long long data = 0;
    for(int i = 1; i <= _min/gcd(w,h); i++){
        int t = ceil(i*left);
        int d = floor((i-1)*left);
        data += (t-d);
    }   
    return answer - (data *(_min/(_min/gcd(w,h))));
}