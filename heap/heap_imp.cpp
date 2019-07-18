#include<iostream>
#include<vector>
using namespace std;

//implimentation of heap using vector (dynamic array)

class heap{
private:
	vector<int> v;
	bool min_heap;

	bool compare(int a,int b){
		if(min_heap){
			return a>b;
		}
		return a<b;
	}

public:
	heap(bool heap_type=true){

		//configuration
		min_heap = heap_type;
		v.push_back(-1);
	}	

	

	void push(int data){

		//insert at last index of new data 
		v.push_back(data);

		int index = v.size() - 1;
		int parent = index/2;

		while(index>1 and compare(v[index],v[parent])){
			swap(v[index],v[parent]);
			index = parent;
			parent = index/2;
		}
		
	}

	bool empty(){
		return v.size() == 1;
	}

	int top(){
		return v[1];
	}
};


int main(){

	heap h;
	h.push(10);
	h.push(20);
	cout<<h.top()<<endl;
	return 0;
}