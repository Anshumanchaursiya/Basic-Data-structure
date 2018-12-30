#include<iostream>
using namespace std;



int fastpower(int a,int n)
{
	if(n==0){
		return 1;
	}

	int smallpower= fastpower(a,n/2);
	smallpower*=smallpower;

	if(n%2==0){
		return(smallpower);
	}
	else
		return(a*smallpower);

	
}

int main()
{
	 int a,n;
	 cout<<"Enter the value of a and n :"; //a to the power n
	 cin>>a>>n;
	 cout<<"Answer is: "<<fastpower(a,n)<<endl;

     return 0;

}
