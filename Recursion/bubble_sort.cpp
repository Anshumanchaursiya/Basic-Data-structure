#include<iostream>
using namespace std;


void bubble(int *a, int n)
{
	int i,j;

	if(n==1){
		return;
	}


	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}

	bubble(a,n-1);

	return;


}

void bubble2(int *a, int n, int i)
{

	if(n==1){
		return;
	}


	if(i<n-1){
		if(a[i]>a[i+1]){
		swap(a[i],a[i+1]);
	    }
	    i++;
	    bubble2(a,n,i);

	}
	i=0;
	

	bubble2(a,n-1,i);

	return;


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

	 bubble(arr,n);

	  for(int i=0;i<n;i++){
	 	cout<<arr[i]<<" ";
	 }



     return 0;

}
