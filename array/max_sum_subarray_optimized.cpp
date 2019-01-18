//Program to find the maximum sum amongst all subarray of given array
//n*n complexity

#include<iostream>
using namespace std;

void max_sum_subarray(int *a,int *cum_sum,int n){

	int current_sum = 0,max_sum = 0;
	int left,right;

	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//update the current sum such that we can calculate sum of every subarray
			current_sum = 0;
			
			if(i==0){
				current_sum = cum_sum[j];
			}
			else{
				current_sum = cum_sum[j] - cum_sum[i-1];

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

	int arr[100],cum_sum[100];
	int n;
	cout<<"Enter the number of eliments: ";
	cin>>n;
	cin>>arr[0];
	cum_sum[0] = arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];

		cum_sum[i] = cum_sum[i-1] + arr[i];

	}

	max_sum_subarray(arr,cum_sum,n);

	return 0;
}
