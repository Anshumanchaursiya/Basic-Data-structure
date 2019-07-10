//problem statement : find nearest k car in 2D cartision

#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

class Car{

	int x;
	int y;
	int id;
public:
	Car(int id,int x,int y){
		this->x = x;
		this->y = y;
		this->id = id;
	}

	int distance(){
		return x*x + y*y;
	}

	void print(){
		cout<<"id: "<<id<<" ";
		cout<<"location: "<<x<<","<<y<<" distance: "<<distance()<<endl;
	}	
};

//Functor : Functional objects
class CarCompare{
public:
	//Method to overload () operator
	bool operator()(Car a,Car b){
		return a.distance() > b.distance();
	}
};

int main(){

	//this Carcompare will automatically called with round bracket
	priority_queue<Car,vector<Car>,CarCompare> pq;

	int x[] = {5,6,17,18,9,11,0,3};
	int y[] = {1,-2,8,9,10,91,1,2};

	//insert these into queue
	for(int i=0;i<8;i++){
		Car c(i,x[i],y[i]);
		pq.push(c);
	}

	while(!pq.empty()){
		Car p = pq.top();
		p.print();
		pq.pop();
	}

	return 0;
}