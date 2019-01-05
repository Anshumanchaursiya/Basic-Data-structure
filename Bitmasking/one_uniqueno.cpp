#include<iostream>
using namespace std;

int find_the_num(int *a,int n)
{
	int ans=a[0];
	for(int i=1;i<n;i++){
		ans^=a[i];
	}

	return ans;
}

int main()
{
	int number,arr[]={2,3,2,3,5,1,8,1,8};
	int n;
	n=sizeof(arr)/sizeof(int);
	cout<<"This is the number occuring only one time: "<<find_the_num(arr,n)<<endl;


	return 0;
}
