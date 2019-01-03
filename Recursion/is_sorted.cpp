#include<iostream>
using namespace std;


bool isSorted(int *a,int n)
{
	if(n==1){
		return true;
	}

	if(a[n-1]>a[n-2]){
		isSorted(a,n-1);

	}
	
	return false;

}


int main()
{
	 int arr[20],n;
	 cout<<"Enter the size of the array: "; 
	 cin>>n;
	 cout<<endl<<"Enter the eliment of the array"<<endl;
	 for(int i=0;i<n;i++){
	 	cin>>arr[i];
	 }

	 if(isSorted(arr,n)){
	 	cout<<"Array is sorted";
	 }
	 else
	 	cout<<"Array is not sorted";
	 cout<<endl;

     return 0;

}
