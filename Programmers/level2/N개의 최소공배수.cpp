#include <string>
#include <vector>

using namespace std;

/*
	알아야할 개념 : gcd (최대 공약수)
	a 와 b의 최소 공배수는 a*b / gcd(a*b)이다
	따라서 gcd를 이용해  원소를 두개씩 비교하며 나온 최소공배수와 
	다음 수를 또 다시 최소공배수를 구하도록 반복하면 
	답을 얻을 수 있다.
*/
int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b,a%b);
}
int solution(vector<int> arr) {
    int answer = 0;
    int gc = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int gc_num = gcd(gc,arr[i]);
        answer = gc * arr[i] / gc_num;
        gc = answer;
    }
    return answer;
}