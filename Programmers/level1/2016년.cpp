#include <string>
#include <vector>

using namespace std;

/*
필요한 자료구조 : 배열 , vector
필요한 개념 : 윤년
시작일이 1월 1일 금요일이니까 가상의 1월 0일 목요일을 정의
목요일은 day의 인덱스 4번째에 위치해있기에 4로 초기화한 뒤, 각 개월의 날짜를 더해 
최종적으로 계산
*/
vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
vector<int> date = {31,29,31,30,31,30,31,31,30,31,30,31};
string solution(int a, int b) {
    int total = 4;
    for(int i = 1; i < a; i++){
        total+= date[i-1];
    }
    total+= b;
    
    return day[total%7];
}