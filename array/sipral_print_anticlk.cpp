#include<iostream>
using namespace std;


void print_spiral(int a[][10],int row,int col){

	int s_row=0,s_col=0,e_row=row-1,e_col=col-1;

	while(s_row<=e_row && s_col<=e_col){

		//printing start column
		for(int i=s_row;i<=e_row;i++){
			cout<<a[i][s_col]<<", ";
		}
		s_col++;

		//printing end row
		for(int j=s_col;j<=e_col;j++){

			cout<<a[e_row][j]<<", ";
		}
		e_row--;

		//printing end col
		for(int k=e_row;k>=s_row;k--){
			//cout<<"hii";
			cout<<a[k][e_col]<<", ";
		}
		e_col--;

		//printing start row
		for(int l=e_col;l>=s_col;l--){
			cout<<a[s_row][l]<<", ";
		}
		s_row++;

	}

}


void read_matrix(int a[][10],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>a[i][j];
		}
	}
}

void init_matrix(int a[][10],int row,int col){

	int counter=1;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			a[i][j] = counter++;
		}
	}
}

int main(){

	int arr[10][10];
	int n,row,col;
	cin>>row>>col;

	//init_matrix(arr,row,col);
	read_matrix(arr,row,col);
	print_spiral(arr,row,col);
	cout<<"END"<<endl;

	return 0;
}
