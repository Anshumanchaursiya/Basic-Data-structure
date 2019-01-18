//Program to find all subarray of a given array

#include<iostream>
using namespace std;

void find_subarray(int *a,int n){

	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){

			for(int k=i;k<=j;k++){
				cout<<a[k]<<",";
			}
			cout<<endl;
		}
	}
}

int main(){

	int arr[100];
	int n;
	cout<<"Enter the number of eliments: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}

	find_subarray(arr,n);

	return 0;
}
