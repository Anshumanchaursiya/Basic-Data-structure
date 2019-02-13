#include<iostream>
#include<algorithm>
using namespace std;

void pair_sum(int *a, int n, int target){
	sort(a,a+n);

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]+a[j] == target){
				cout<<endl<<a[i]<<" and "<<a[j]<<endl;
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

	pair_sum(arr,n,target);
	

	return 0;
}
