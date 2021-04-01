using namespace std;
/*
	해당 문제는 반복문으로 연속적인 숫자를 더하다가 
	총 값이 n을 넘을 경우 처음부터 하나씩 빼가면서 
	n과 sum이 일치하도록 구현하는 것을 목표로 한다.
*/
int solution(int n) {
    int num = (n + 1) / 2;
    int sum = 0, answer = 1, j = 1;
    
    for(int i = 1; i <= num; i++){
        sum += i;
        if(sum >= n){
            while(sum > n) sum -= j++;
            if(sum == n) answer++;
        }
    }
    
    return answer;
}
