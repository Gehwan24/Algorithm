#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int big;
	int small;
	int temp;
	if (n > m) {
		big = n; small = m;
	}
	else {
		big = m; small = n;
	}
	while (small != 0){
		temp = big % small;
		big = small;
		small = temp;
	}
	answer.push_back(big);
	answer.push_back(m*n/big);
	return answer;
}