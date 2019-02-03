#include<iostream>
#include<cstring>

using namespace std;

int main(){

	char stringlist[20][100];
	int n,i;
	cout<<"How much string: "<<endl;
	cin>>n;
	cin.ignore(); //to ignore the enter after n

	cout<<"Enter all string: "<<endl;
	for(int i=0;i<n;i++){
		cin.getline(stringlist[i],20);
	}

	char key[20];
	cout<<"Enter the string you want to search: ";
	cin.getline(key,20);

	

	for(i=0;i<n;i++){

		//compare two string 
		if(strcmp(key,stringlist[i])==0){ 
			cout<<"Found at index: "<<i;
			break;
		}
		
	}
	//if not found at any index

	if(i==n){
		cout<<"Not found"<<endl;
	}

	return 0;
}
