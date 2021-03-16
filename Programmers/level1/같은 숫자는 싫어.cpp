#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
사용한 자료구조 : vector
사용하면 괜찮은 함수 : erase, unique

unique는 해당 백터에서 연속되는 중복된 값을 확인하는 기능
연속하지 않을경우 다른 값으로 인식
erase를 함께 진행할 경우, unique로 인식한 값 이외의 모든 중복값 제거

*/
vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(),arr.end()),arr.end());    
    return arr;
}