#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 필요한 개념 : 인덱싱
 케이스에 따라 방향을 설정해가며 숫자를 배열에 입력하는 
 방식으로 구현을 진행함
*/
int dir = 0; // 0 아래, 1 오른쪽, 2 위, 3 그대로
int arr[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int px = -1;
    int py = n+1;
    int count = 1;
    int temp = n;
    while (temp) {
        for (int i = 1; i <= temp; i++) {
            switch (dir) {
            case 0:
                px++, py--;
                arr[px][py] = count;
                break;
            case 1:
                py++;
                arr[px][py] = count;
                break;
            case 2:
                px--;
                arr[px][py] = count;
                break;
            }
            count++;
        }

        dir = (dir + 1) % 3;
        temp--;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++)
        {
            if(arr[i][j])
                answer.push_back(arr[i][j]);
        }
    }   
    return answer;
}
