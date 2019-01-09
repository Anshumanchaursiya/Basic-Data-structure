#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


int main(){

	stack<int> s1;
	stack<string> s2; 

	s1.push(1);
	s1.push(2);
	s1.push(3);

	cout<<"This is your stack of integer: "<<endl;

	while(!s1.empty()){
		cout<<s1.top()<<endl;
		s1.pop();
	}

	s2.push("apple");
	s2.push("mango");
	s2.push("lemon");

	cout<<endl<<"this is your stack of string "<<endl;

	while(!s2.empty()){
		cout<<s2.top()<<endl;
		s2.pop();
	}
	cout<<endl;


	return 0;
}

