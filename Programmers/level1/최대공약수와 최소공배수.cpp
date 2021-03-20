#include <string>
#include <vector>

using namespace std;
/*
  알면 좋은 개념 : GCD 최대공약수,유클리드 방법 이용
	최소공배수 , 곱한 두 수/ 최대공약수
*/
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(n*m/gcd(n,m));
    return answer;
}