

#include<iostream>
using namespace std;

//to find left max from the perticular ith buildings
int left_max(int *a,int n,int i){
	int leftmax = a[i];

	for(int j=i;j>=0;j--){
		if(a[i]<a[j]){
			leftmax = a[j];
		}

	}
	//cout<<" left max "<<leftmax<<endl;

	return leftmax;
}

int right_max(int *a,int n,int i){

	int rightmax = a[i];

	for(int j=i;j<n;j++){
		if(a[i]<a[j]){
			rightmax = a[j];
		}
	}

	return rightmax;
}

int collected_water(int *a,int n){

	int left[10000],right[10000];
	int total_water = 0;

	if(n==0 || n==1 || n==2){
		return 0;
	}

	for(int i=0;i<n;i++){

		int l = left_max(a,n,i);
		int r = right_max(a,n,i);
		total_water = total_water + (min(l,r) - a[i]);
		//to find collected water at every top of the building->
		//cout<<total_water<<" ";
	}

	return total_water;


}

int main(){

	int n,building[10000];
	cout<<"Enter the number of buildings: ";
	cin>>n;
	cout<<"Enter the height of buildings: "<<endl;

	for(int i=0;i<n;i++){

		cin>>building[i];
	}

	cout<<"water collected between the buildings is "<<collected_water(building,n)<<" unit"<<endl;


	return 0;
}
