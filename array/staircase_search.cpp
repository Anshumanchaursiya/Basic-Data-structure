//in o(m+n) time complexity

#include<iostream>
using namespace std;

void read_array(int arr[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
}

void search_eliment(int arr[][200],int row,int col,int eliment){

	int i=0,j=col-1;

	while(i<row and j>=0){
		if(arr[i][j]==eliment){
			cout<<"\nFound eliment ar index: "<<i<<" "<<j<<endl;
			break;
		}
		else if(arr[i][j]>eliment){
			j--;
		}
		else{
			i++;
		}
	}
}

int main(){

	int arr[100][200];
	int row,col,eliment;
	cout<<"Enter the number of rows and col: ";
	cin>>row>>col;
	cout<<"\nEnter the eliments of the array: \n";

	read_array(arr,row,col);
	cout<<"Enter the eliment you want to search: ";
	cin>>eliment;

	search_eliment(arr,row,col,eliment);

	return 0;
}
