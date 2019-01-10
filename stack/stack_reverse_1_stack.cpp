#include<iostream>
#include<stack>

using namespace std;


void move(stack<int> &s1,stack<int> &s2){
	
	s2.push(s1.top());
	s1.pop();
}

void reverse_stack(stack<int> &s1){
	stack<int> s2;
	int n = s1.size();

	for(int i =0;i<n;i++){
		int x = s1.top();
		s1.pop();

		//move the elimnent from s1 to s2 that is not reversed
		for(int j=0;j<n-i-1;j++){
			move(s1,s2);
		}
		s1.push(x);
		for(int j=0;j<n-i-1;j++){
			move(s2,s1);
		}
	}

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
