#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 이건 정렬 후 최댓값 최솟값 곱해주기...
*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0 ; i < A.size(); i++)
        answer+= A[i] * B[A.size()-i-1];
    return answer;
}