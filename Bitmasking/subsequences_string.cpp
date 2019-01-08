#include<iostream>
#include<cstring>
using namespace std;

//to find the string corrosponding number 
void filterstring(char *a,int number){
	int i=0;
	while(number>0){
		if(number&1){
			cout<<a[i];
		}    
		else{
			cout<<" ";
		}
		i++;
		number=number>>1;
	}
	cout<<endl;
}

//to generate all the number 0 to range 
void generatestring(char *a){
	int n,range;
	n=strlen(a);
	range=((1<<n)-1);
	for(int i=0;i<=range;i++){

		filterstring(a,i);
	}

}


int main(){

	char arr[10];
	cout<<"Enter string you want to know subsequences: ";
	cin>>arr;
	cout<<"this is all subsequences: ";
	generatestring(arr);
	cout<<endl;

	return 0;
}
