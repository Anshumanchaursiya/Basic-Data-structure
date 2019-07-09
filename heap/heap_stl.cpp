#include<iostream>
#include<queue>
using namespace std;


int main(){

	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(10);
	//by default priority queue is max heap
	cout<<"top: "<<pq.top()<<endl;

	while(!pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
	return 0;
}