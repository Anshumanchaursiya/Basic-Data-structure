#include<iostream>
#include<stack>
using namespace std;

bool balanceparenthesis(string str){
	stack<char> s;
	for(i = 0;i<str.lenth();i++){
		char curr = str[i];
		if(curr == '('){
			s.push(curr);

		}
	}
	else if(curr == ')'){
		if(s.empty()){
			return false;
		}
		s.pop();
	}
	
	return s.empty();
}


int main(){
	string str;
	cin>>str;
	if(balanceparenthesis(str)){
		cout<<"yes";
	}


	return 0;
}


