#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


int main(){
	//for min heap
	priority_queue<int,vector<int>,greater<int> > pq;
	pq.push(1);
	pq.push(2);
	pq.push(10);
	cout<<"top: "<<pq.top()<<endl;

	while(!pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
	return 0;
}