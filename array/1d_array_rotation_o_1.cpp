#include<iostream>
using namespace std;

void rotate_arr(int *arr,int d,int n){

	if(n == 0 or d == 0){
		return;
	}
	int i=0;
	int temp;
	cout<<arr[i]<<" "<<endl;
	while(d--){
		temp = arr[i];
		int j = i;
		int k = i+1;
		while(k!=n){
			arr[j++] = arr[k++];
		}
		
		arr[k-1] = temp;
	}
	return;

}

int main(){

	int arr[] = {1,2,3,4,5,6,7};
	int d,n;
	n = sizeof(arr)/sizeof(int);
	cout<<"Input d: ";
	cin>>d;
	rotate_arr(arr,d,n);
 
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}