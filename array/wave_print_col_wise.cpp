#include<iostream>
using namespace std;

void init_matrix(int a[][10],int row,int col){

	int start=1;
	for(int i=0;i<row;i++){

		for(int j=0;j<col;j++){
			a[i][j] = start++;
		}
	}
}

void print_the_matrix(int a[][10],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<a[i][j]<<" \t";
		}
		cout<<endl;
	}
}


void print_wave(int arr[][10],int row,int col){

	int i=0,j=0;

	for(int v=0;v<col;v++){
		
		if(i == row){
			for(int k=0;k<row;k++){
				cout<<arr[--i][j]<<",";
			}
			j++;
		}

		else{
			for(int k=0;k<row;k++){
				cout<<arr[i++][j]<<",";
			}
			j++;
		}
		
	}

	cout<<"END"<<endl;

}

void kread_matrix(int arr[][10],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
}

int main(){

	int arr[10][10];
	int row,col;
	cin>>row>>col;

	init_matrix(arr,row,col);
	print_the_matrix(arr,row,col);
	print_wave(arr,row,col);

	return 0;
}
