#include<iostream>
using namespace std;

int set_ith_bit(int n,int i){
	
	return( n | 1<<i);
}


int main()
{
	int n,i;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"At which position you want to set the bet: ";
	cin>>i;
	cout<<set_ith_bit(n,i);
	cout<<endl;
	return 0;
}
