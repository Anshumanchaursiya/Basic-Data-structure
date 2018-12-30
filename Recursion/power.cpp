#include<iostream>
using namespace std;



int power(int a,int n)
{
	if(n==0){
		return 1;
	}

	int ans=a*power(a,n-1);
	return ans;
}



int main()
{
	 int a,n;
	 cout<<"Enter the value of a and n :"; //a to the power n
	 cin>>a>>n;
	 cout<<"Answer is: "<<power(a,n)<<endl;

     return 0;

}
