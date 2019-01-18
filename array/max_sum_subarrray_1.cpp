//Program to find the maximum sum amongst all subarray of given array

#include<iostream>
using namespace std;

void max_sum_subarray(int *a,int n){

	int current_sum = 0,max_sum = 0;
	int left,right;

	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//update the current sum such that we can calculate sum of every subarray
			current_sum = 0;
			for(int k=i;k<=j;k++){
				//to find the sum of eliment in the subarray
				current_sum+=a[k];
			}

			//updata the maximum sum if the maximum sum is less than the current sum
			if(max_sum<current_sum){
				max_sum = current_sum;
				left = i;
				right = j;
			}
			
		}
	}
	cout<<"Maximum sum is = "<<max_sum<<endl;
	cout<<"subarray is: ";
	for(int i=left;i<=right;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
}

int main(){

	int arr[100];
	int n;
	cout<<"Enter the number of eliments: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}

	max_sum_subarray(arr,n);

	return 0;
}
