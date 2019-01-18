#include<iostream>
using namespace std;

//kadanes algorithm
void kadanes(int *a, int n){

	int current_sum =0,max_sum = 0;

	for(int i=0;i<n;i++){
		if((current_sum + a[i]<0)){
			current_sum+=0; //or current_sum = 0;
		}
		else{
			current_sum+=a[i];
		}

		//update the maximum sum
		max_sum = max(max_sum,current_sum);
	}

	cout<<endl<<"maximum sum is: "<<max_sum;
}

int main(){

	int arr[100];
	int n;

	cout<<"Enter the number of eliments: ";
	cin>>n;
	cout<<"Enter the number: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	kadanes(arr,n);
	cout<<endl;

	return 0;
}
