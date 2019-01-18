#include<iostream>
using namespace std;

int linear_search(int *a,int n,int key,int i){

	if(n==0 or i>n){
		return -1;
	}

	if(a[i] == key){
		return i;
	}
	else{
		linear_search(a,n,key,i+1);
	}
	
}

int main(){

	int arr[100];
	int key,n;

	cout<<"Enter the number of eliments: ";
	cin>>n;
	cout<<endl<<"Enter the eliments "<<endl;
	for(int i=0;i<n;i++){

		cin>>arr[i];
	}

	cout<<"Enter the key: ";
	cin>>key;

	int index = linear_search(arr,n,key,0);
	if(index == -1){
		cout<<endl<<"Not found";
	}
	else{
		cout<<endl<<"found at "<<index<<endl;
	}
	cout<<endl;
	return 0;
}
