#include <iostream>
using namespace std;

int first_occurence(int *a,int s,int e){
    int mid = (s+e)/2;
    if(s>=e){
        return mid;
    }
    if(a[mid]==0 and a[mid-1]==1){
        return mid;
    }
    if(a[mid]==0){
        first_occurence(a,s,mid-1);
    }
    else{
        first_occurence(a,mid+1,e);
    }
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int a[10000];
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int f_index = first_occurence(a,0,n-1);
	    //cout<<f_index<<endl;
	    cout<<(n-f_index)<<endl;
	}
	return 0;
}