#include<iostream>
using namespace std;

int main()
{

	int n;
	cout<<"Enter the number: ";
	cin>>n;    //using bitwiise and operator
	if(n&1){
		cout<<"Number is odd"<<endl;
	}
	else{
		cout<<"Number is even"<<endl;
	}

	(n&1)?cout<<"odd":cout<<"even"; //in one line code
	cout<<endl;

	return 0;
}
