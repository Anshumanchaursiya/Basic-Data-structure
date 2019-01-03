#include<iostream>
using namespace std;



int ways_fill(int n)
{ 

	int ans;
	if(n<=3){
		return 1;
	}

	ans+=ways_fill(n-1)+ways_fill(n-4);

	return ans;
}

int main(){
	int n;
	cout<<"wall size is 4*n"<<endl<<"Brick size is 4*1"<<endl<<"Enter the value of n: ";
	cin>>n;
	cout<<"This is the ways to fill the brick in the wall: "<<ways_fill(n)<<endl;

	return 0;
}
