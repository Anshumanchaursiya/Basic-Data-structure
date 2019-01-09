//Implimentation of stack using vector data structure

#include<iostream>
#include<vector>

using namespace std;

class stack{
private:
	std::vector<int> v;

public:

	void push(int data){
		v.push_back(data);
	}

	bool IsEmpty(){
		return v.size() == 0;
	}

	void pop(){
		if(!IsEmpty()){
			v.pop_back();
		}
		else{
			cout<<"Stack is empty "<<endl;
		}
	}

	int top(){
		if(!IsEmpty()){
			return v[v.size() - 1];

		}
		else{
			cout<<"Stak is empty"<<endl;
		}
	}

/*	void print(){
		if(!IsEmpty()){
			cout<<top()<<endl;
			pop();
		}
		else{
			return;
		}
	}

*/

};



int main(){

	stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	while(not s.IsEmpty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;


	return 0;
}
