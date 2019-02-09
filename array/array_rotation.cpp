//this implimentation is done without taking an extra array means o(1) space

#include<iostream>
using namespace std;

void read_matrix(int arr[][200],int row,int col){

	int num=1;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j] = num++;
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

void mirror_matrix(int arr[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(j<=(col/2)){
				swap(arr[i][j],arr[i][col-1-j]);
				//arr[i][j] = arr[i][col-1-j];
			}
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
	cout<<"Enter the rows and column: ";
	cout<<"\nnote: it should be squire matrix: \n";
	cin>>row>>col;

	read_matrix(arr,row,col);
	cout<<"This is the original matrix: "<<endl;
	print_matrix(arr,row,col);
	transpose_matrix(arr,row,col);
	mirror_matrix(arr,row,col);
	cout<<"\nThis is the required matrix: \n";
	print_matrix(arr,row,col);
	cout<<endl;

	return 0;
}
