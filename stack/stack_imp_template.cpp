#include<iostream>
#include<vector>

using namespace std;

template<typename T>

class stack{
private:
	vector<T> v;

public:

	void push(T data){
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

	T top(){
		if(!IsEmpty()){
			return v[v.size() - 1];

		}
		else{
			cout<<"Stak is empty"<<endl;
		}
	}


};



int main(){

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	cout<<endl<<"this is top: "<<s.top()<<endl;

	while(not s.IsEmpty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;


	return 0;
}
