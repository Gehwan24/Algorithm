/*
요구조건
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

단순 구현인데....
생각보다 오래 걸림 ㅠㅠ step에 따라 각 정의된 문제 모듈로 구현
이런건 python으로 해야될듯 
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
string step_one(string t){
		string change_t ="";
		for(int i = 0; i < t.size(); i++)
				change_t += isupper(t[i]) ? (t[i] + 32) : t[i];
		return change_t;		
}
string step_two(string t){
	string remove_t = "";
	for(char c : t){
		if(isalpha(c) | (c == '-') | isdigit(c) | (c =='_') | (c=='.'))
			remove_t += c;
	}
	return remove_t;
}
string step_three(string t){
		string double_t = "";
		for(int i = 0; i < t.size(); i++)
	{
		double_t+=t[i];
		if(t[i] == '.'){
			while(i+1 < t.size())
			{
				if(t[i+1] == '.')
					i++;
				else
					break;
			}
		}
	}
	cout << double_t << endl;
	return double_t;
}
string step_four(string t){
	string remove_t = t;
	if(remove_t.size() > 0){
		if(remove_t[0] == '.')
			remove_t.erase(remove_t.begin());	
	}
	if(remove_t.size() > 0){
		if(remove_t[remove_t.size()-1] == '.')
			remove_t.pop_back();	
	}
	cout << remove_t << endl;
	return remove_t;
}

string step_five(string t){
	return (t.size() == 0) ?	"a" : t;
	
}
string step_six(string t){
	if(t.size() < 16)
		return t;
	else{
		string remove_t = t.substr(0,15);
		if(remove_t[remove_t.size()-1] == '.')
			remove_t.pop_back();	
			return remove_t;
	}
	
}
string step_seven(string t){
	cout << t << endl;
	string copy_t = t;
	if(copy_t.size() <= 2){
		while(copy_t.size() <3){
			copy_t += copy_t[copy_t.size()-1];
		}
	}
	return copy_t;
}
string solution(string new_id) {
    string answer = "";
		answer = step_one(new_id);					
		answer = step_two(answer);					
		answer = step_three(answer);					
		answer = step_four(answer);					
		answer = step_five(answer);					
		answer = step_six(answer);					
		answer = step_seven(answer);					
    return answer;
}