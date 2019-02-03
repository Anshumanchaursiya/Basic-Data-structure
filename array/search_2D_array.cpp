//search with time complexity order of n

#include<iostream>
//#include <tuple>
using namespace std;

void read_the_matrix(int a[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>a[i][j];
		}
	}
}

void print_the_matrix(int a[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}

void search_the_eliment(int a[][200],int row,int col,int search){

	for(int i=0;i<row;i++){
		for(int j=col-1;j>=0;j--){
			if(a[i][j]>=search){
				if(a[i][j]==search){
					cout<<"index found: "<<i<<","<<j<<endl;
					return;
				}
			}
		}
	}
	cout<<"eliment is not found"<<endl;
}

int main(){

	int arr[10][200];

	int row,col,search;
	cout<<"Enter the row and column: ";
	cin>>row>>col;

	read_the_matrix(arr,row,col);

	print_the_matrix(arr,row,col);

	cout<<"Which eliment you want to search: ";
	cin>>search;

	search_the_eliment(arr,row,col,search);

	return 0;
}
