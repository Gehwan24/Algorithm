#include <string>
#include <vector>

using namespace std;
/*
  이 문제 또한 각자리 수를 더해 나누어 떨어지느냐만 판단하느 것이기 때문에
	각자리 수로 나눠서 각 자리를 더하고 이를 나누어본다.
*/
bool solution(int x) {
    int n = x; 
    int each_x = 0;
    while(n){
        each_x += n%10;
        n/=10;
    }
    return (x % each_x) ? false : true;
}