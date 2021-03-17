#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
 주의해야할 개념 : sqrt를 사용할때 곱하기 전에 형변환을 안해주면 
 소수점이 곱해져서 내가 원하는 정수값이 안나올수도 있다는점..
*/
long long solution(long long n) {
    long long sqrt_n = (long long)sqrt(n) * (long long)sqrt(n);
    return n == sqrt_n ? (long long)(sqrt(n)+1)*(long long)(sqrt(n)+1) :-1;
}