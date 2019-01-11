#include<iostream>
#include<queue>

using namespace std;

int main(){

	queue<int> q;

	for(int i=0;i<10;i++){
		q.push(i*i);
	}

	for(int i=0;i<10;i++){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;


	if(q.empty()){
		cout<<"Now queue is empty"<<endl;
	}


	return 0;
}
