#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 필요한 자료구조 : 딱히 없는듯? 
 3진법이니 진법에 대한 이해도만 있으면 구현 가능
*/
string int_to_num_3rd(int n){
    string t = "";
    while(n){
        t+=(n%3) + '0';
        n /= 3;
    }
    return t;
}
int num_to_int_3rd(string t){
    int total = 0;
    for(int i = 0 ; i < t.size(); i++)
    {
        total = total*3 + (t[i]-'0');
    }
    return total;
}
int solution(int n) {
    int answer = 0;
    string make_three = int_to_num_3rd(n);
    answer = num_to_int_3rd(make_three);
    return answer;
}