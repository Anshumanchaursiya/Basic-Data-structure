#include<iostream>
using namespace std;

//time taken o(number of bits)
int no_setbits(int n){
	int ans=0;
	while(n>0){
		
		ans+=(n&1);
		n=n>>1;    //using bitwise operator  it can be written also as n>>=1
	}
	return ans;
}


//time taken to calculate the number of setbits in this set of code is
int count_bitsfast(int n){
	int count=0;
	while(n>0){
		n&(n-1);
		count++;
	}

	return count;
} 

int main()
{
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"No of set bits is: "<<no_setbits(n)<<endl;
	cout<<"Using complexity of bogo of nnumber of setbits, number of 1s is: "<<count_bitsfast(n)<<endl;
	cout<<"Using bilt in function: "<<__builtin_popcount(n)<<endl;

	return 0;
}
