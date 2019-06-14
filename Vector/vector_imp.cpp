#include<iostream>
using namespace std;

class Vector{

private:
	int *arr;
	int cs;
	int maxsize;

public:

	Vector(int defaultsize){
		cs =0;
		maxsize = defaultsize;
		arr = new int[maxsize];
	}

	void push_back(int data){
		if(cs == maxsize){
			int *oldarray = arr;
			arr = new int[2*maxsize];
			maxsize = 2* maxsize;

			for(int i=0;i<cs;i++){
				arr[i] = oldarray[i];
			}

			//deleting old array to free up the memory
			delete [] oldarray;
		}

		arr[cs] = data;
		cs++;
	}

	bool empty(){
		return cs==0;
	}

	void pop_back(){

		//if vector is non empty
		if(!empty()){
			cs--;
		}

		else{
			return;
		}
	}

	int at(int k){
		return arr[k];
	}

	void print(){

		for(int i=0;i<cs;i++){
			cout<<arr[i]<<",";
		}
		cout<<endl;
	}

	int getmaxSize(){
		return maxsize;
	}

};

int main(){


	Vector v1(5);

	v1.push_back(1);
	v1.push_back(2);
	v1.print();
	cout<<"Max size of vector = "<<v1.getmaxSize()<<endl;
	return 0;
}