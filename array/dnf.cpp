#include<iostream>
using namespace std;



void dnf(int *a,int n)
{
  int i,temp,end,start=0,mid=0;
  end=n-1;
  while(mid<end)
  {
    if(a[mid]==1){
	mid++;
        }
    else if(a[mid]==2){
	swap(a[mid],a[end]);
	end--;
	}
    else{
	swap(a[mid],a[start]);
	start++;
	mid++;
	}
  }

}
   




int main()
{
  int arr[]={1,0,0,1,2,0,2,1,0,0};
  int n,i;
  n=sizeof(arr)/sizeof(int);
  dnf(arr,n);

  for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }

 cout<<endl;
 return 0;
}
