//this implimentation is done without taking an extra array means o(1) space

#include<iostream>
using namespace std;

void read_matrix(int arr[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
}

void transpose_matrix(int arr[][200],int row,int col){

	int temp;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){

				while(i>j){
				
				temp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = temp;
				break;
			}
		}	
	}
}

void mirror_matrix_about_x_axis(int arr[][200],int row,int col){

	for(int j=0;j<col;j++){
		for(int i=0;i<row/2;i++){
			
			swap(arr[i][j],arr[row-i-1][j]);
		}

	}

}

void print_matrix(int arr[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){

	int arr[100][200];
	int row,col;//row and column will be same it should be squire matrix
	cin>>row;
	col = row;

	read_matrix(arr,row,col);
	//print_matrix(arr,row,col);
	transpose_matrix(arr,row,col);
	mirror_matrix_about_x_axis(arr,row,col);
	print_matrix(arr,row,col);
	cout<<endl;

	return 0;
}
