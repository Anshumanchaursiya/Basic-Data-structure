#include<iostream>
using namespace std;

int ways(int n)
{
	int ans;

	if(n==1 or n==0){
		return 1;
	}

	ans=ways(n-1)+(n-1)*ways(n-2);
	return ans;
}


int main()
{
	int num_of_bike;
	cout<<"Enter the number of bike: ";
	cin>>num_of_bike;
	cout<<"This is the number of ways to go in party with bike: "<<ways(num_of_bike)<<endl;


	return 0;
}

