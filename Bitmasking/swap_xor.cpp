#include<iostream>
using namespace std;

void swap(int *a,int *b){

	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}

int main(){
	int a,b;
	cout<<"Enter the number of a and b "<<endl;
	cin>>a>>b;
	swap(&a,&b);
	cout<<endl<<"After swapping number is: "<<a<<" "<<b<<endl;

	return 0;
}
