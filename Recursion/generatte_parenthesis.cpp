#include<iostream>
using namespace std;

void generate_parenthsis(int n,string str,int open,int close){


	if(close==open and close>=n){
		cout<<str<<endl;
		return;
	}

	if(open<n){
		generate_parenthsis(n,str+'(',open+1,close);

	}

	if(close<open){
		generate_parenthsis(n,str+')',open,close+1);
	}


}


int main(){
	int n;

	cout<<"Enter the number: ";
	cin>>n;

	generate_parenthsis(n,"",0,0);
	cout<<endl;

	return 0;
}
