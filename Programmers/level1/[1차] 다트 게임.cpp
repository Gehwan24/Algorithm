#include <string>
#include <vector>

/*
숫자뒤에 무조건 SDT가 오는 점을 이용해 
해당 문자가 오는 경우 VECTOR에 저장하는 방식으로 진행
옵션이 존재할 경우 각 옵션에 알맞는 상황을 구현해줬음
*/
using namespace std;
vector<int> num;
int solution(string dartResult) {
    int answer = 0;
    int number = 0;
    for(int i = 0 ; i < dartResult.size(); i++){
        if(i != 0){
            if(isdigit(dartResult[i]))
                number = number*10 + (dartResult[i]-'0');
            else if(isalpha(dartResult[i])){
                switch(dartResult[i]){
                    case 'S':
                        num.push_back(number);
                        break;
                    case 'D':
                        num.push_back(number*number);
                        break;
                    case 'T':
                        num.push_back(number*number*number);
                        break;
                }
                number = 0;
            }
            else {
                if(dartResult[i] == '*'){
                    if(num.size() == 1){
                        num.back() *= 2;
                    }else{
                        num.back() *= 2;
                        num[num.size()-2]*=2;
                    }
                }
                else
                    num.back() *= -1;
            }
        }
        else
            number = dartResult[i] - '0';  
    }
    for(int i : num)
        answer+= i;
    return answer;
}