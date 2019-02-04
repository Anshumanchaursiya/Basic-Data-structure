#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a,int b){
	//for descending order
	return a>b;
}

int main(){

	int a[10] = {6,3,7,2,12,0,4,11};
	int b[10] = {6,3,7,2,12,0,4,11};
	int n1 = sizeof(a)/sizeof(int);
	int n2 = sizeof(b)/sizeof(int);

	// by default is sort in ascending order
	sort(a,a+n1);
	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n1;i++){
		cout<<a[i]<<" ";
	}

	//to sort in discending order
	sort(b,b+n2,compare);
	cout<<"\nIn discending order: "<<endl;
	for(int i=0;i<n2;i++){
		cout<<b[i]<<" ";
	}

	cout<<endl;

	return 0;
}
