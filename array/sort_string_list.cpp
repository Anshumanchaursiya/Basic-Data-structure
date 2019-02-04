#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

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
	cout<<"Sorted strings: "<<endl<<endl;
	for(int i=0;i<7;i++){
		cout<<s[i]<<endl;
	}

	return 0;
}
