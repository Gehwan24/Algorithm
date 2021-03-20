#include <string>
#include <vector>

using namespace std;

/* 짝수랑 홀수 판별하는 알고리즘 
*/
string solution(int num) {
    return (num&1) ? "Odd" : "Even";
}