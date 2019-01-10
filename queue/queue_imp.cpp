#include<iostream>
using namespace std;

template<typename T>

class queue{
private:
	T *arr;
	T front;
	T rear;
	T ms;
	T cs;

public:

	queue(T ds = 4){
		arr = new T[ds];
		front =0;
		rear = ds - 1;
		ms = ds;
		cs = 0;
	}

	bool isfull(){
		return cs == ms;
	}

	bool isempty(){
		
		return cs == 0;
	}

	void en_queue(int data){
		if(not isfull()){
			rear = (rear+1)%ms;
			arr[rear] = data;
			cs++;
		}
		
	}

	void de_queue(){
		if(! isempty()){
			front = (front+1)%ms;
			cs-=1;
		}
		
	}

	T getfront(){
		if(! isempty()){
			return front;
		}
		else{
			cout<<endl<<"Array is empty"<<endl;
		}
		
	}

	T getrear(){
		return rear;
	}


};



int main(){
	queue<int> q1(8);

	for(int i =0;i<8;i++){
		q1.en_queue(i);
		

	}

	for (int i = 0; i < 8; ++i)
	{
		cout<<q1.getfront();
		q1.de_queue();
		cout<<" ";
	}
	
	cout<<endl;

	return 0;
}
