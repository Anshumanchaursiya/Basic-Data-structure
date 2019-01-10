#include<iostream>
#include<stack>

using namespace std;


void move(stack<int> &s1,stack<int> &s2,int n){
	

	for(int i =0;i<n;i++){
		s2.push(s1.top());
    	s1.pop();
	
	}
}	

void reverse_stack(stack<int> &s1){
	stack<int> s2;
	stack<int> s3;
	int n = s1.size();

	move(s1,s2,n);
	move(s2,s3,n);
	move(s3,s1,n);
}

int main(){

	stack<int> s;

	for(int i=0;i<5;i++){
		s.push(i);
	}

	reverse_stack(s);
	reverse_stack(s);
	while(! s.empty()){
		cout<<s.top()<<" " ;
		s.pop();
	}

	cout<<endl;

	return 0;
}
