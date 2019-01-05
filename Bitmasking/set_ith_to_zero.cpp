#include<iostream>
using namespace std;

int set_ith_bit_0(int n,int i){

	return(n&(~(1<<i)));//first left shitft upto i and then flip it then after or with the given number n
}


int main()
{
	int n,i;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"At which position you want to set the bet: ";
	cin>>i;
	cout<<set_ith_bit_0(n,i);
	cout<<endl;
	return 0;
}
