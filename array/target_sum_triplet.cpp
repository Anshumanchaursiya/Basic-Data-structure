#include<iostream>
#include<algorithm>
using namespace std;

void target_triplet_sum(int *a,int n,int target){

	sort(a,a+n);

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k] == target){
					cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
				}
			}
		}
	}
}

int main(){

	int arr[1000];
	int n,target;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>target;

	target_triplet_sum(arr,n,target);


	return 0;
}
