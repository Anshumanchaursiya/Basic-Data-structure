#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int a[10] = {6,3,7,2,12,0,4,11};
	int n = sizeof(a)/sizeof(int);

	sort(a,a+n);
	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}
