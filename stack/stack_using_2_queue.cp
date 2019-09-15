#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class stack_using_q{

	queue<int> q1,q2;
public:

	void push(int d){
		q1.push(d);
	}

	void pop(){
		int n = q1.size();
		for(int i=0;i<n-1;i++){
			q2.push(q1.front());
			q1.pop();
		}

		
		q1.pop();
		
		
		swap(q2,q1);
	}

	int top(){
		int n = q1.size();
		for(int i=0;i<n-1;i++){
			q2.push(q1.front());
			q1.pop();
		}

		int topEliment = q1.front();
		q1.pop();
		q2.push(topEliment);
		swap(q1,q2);
		return topEliment;
	}

	int size(){

		return q1.size();
	}

};

int main(){

	stack_using_q s;
	s.push(2);
	s.push(3);
	cout<<"top Eliment: "<<s.top()<<endl;
	s.pop();
	s.push(4);
	cout<<"top Eliment: "<<s.top()<<endl;

	int size = s.size();
	for(int i=0;i<size;i++){
		cout<<i<<":";
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;

	return 0;
}
