#include <string>
#include <vector>
using namespace std;
int solution(string name) {
	int answer = 0;
	vector<int> position;
	char N = 'N';int count = 0;int check_count = 0;int front;int back;
	for (int i = 0; i < name.size();i++){
		if (name[i]<N)
			answer += name[i] - 'A';
		else
			answer += 'A' - name[i] + 26;
		if (name[i] != 'A')
			if(i != 0)
				position.push_back(i);
	}	
	while (!position.empty()){
		front = (position.front() - check_count + name.size())% name.size();
		back = (name.size() - position.back() + check_count)% name.size();
		if (front > back){
			count += back;
			check_count = position.back();
			position.pop_back();
		}
		else{
			count += front;
			check_count = position.front();
			position.erase(position.begin());
		}
	}
	answer += count;
	return answer;
}