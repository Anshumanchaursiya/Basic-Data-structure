#include<iostream>
using namespace std;

int fact(int a)
{
	if(a==0)
		return 1;

	//recursive case
	int ans=a*fact(a-1);

	return(ans);
}



int main()
{
	 int n;
	 cout<<"Enter the number: ";
	 cin>>n;
	 cout<<"Factorial of this number is "<<fact(n);
	 cout<<endl;

	 return 0;
}
