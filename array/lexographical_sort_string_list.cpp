#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool compare(string s1,string s2){
	return s1>s2;
}


int main(){

	string s[10] = {
		"pulkit",
		"rubin",
		"gyan",
		"ansh",
		"manish",
		"alok",
		"rahul"
	};

	sort(s,s+7);
	cout<<" In assending order Sorted strings: "<<endl<<endl;
	for(int i=0;i<7;i++){
		cout<<s[i]<<endl;
	}
	cout<<endl;
	
	sort(s,s+7,compare);
	cout<<"In discending order: "<<endl;

	for(int i=0;i<7;i++){
		cout<<s[i]<<endl;
	}

	return 0;
}
