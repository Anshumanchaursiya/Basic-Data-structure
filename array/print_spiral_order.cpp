//print in spiral order of a 2D matrix

#include<iostream>

using namespace std;

void init_matrix(int a[][200],int row,int col){

	int start=1;
	for(int i=0;i<row;i++){

		for(int j=0;j<col;j++){
			a[i][j] = start++;
		}
	}
}

void print_the_matrix(int a[][200],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<a[i][j]<<" \t";
		}
		cout<<endl;
	}
}

void print_in_spiral(int a[][200],int row,int col){

	int s_row=0,e_row=row-1,s_col=0,e_col=col-1;

	while(e_row>=s_row && e_col>=s_col){

		//printing start row
		for(int j=s_col;j<=e_col;j++){
			cout<<a[s_row][j]<<" ";
			
		}
		s_row++;
		
		//printing end column
		for(int i=s_row;i<=e_row;i++){
			cout<<a[i][e_col]<<"  ";
			
		}
		e_col--;

		//printing end row - it is printed when end row > start row
		if(e_row>s_row){
			for(int j=e_col;j>=s_col;j--){
				cout<<a[e_row][j]<<"  ";
			}
		
			e_row--;
		} 
		
		//printing start column - it is printed when end column > start column
		if(e_col<s_col){
			for(int i=e_row;i>=s_row;i--){
				cout<<a[i][s_col]<<"  ";
			
			}
			s_col++;
		}	

	}


}

int main(){

	int arr[100][200];
	int row,col;
	cout<<"Enter the row and column: "<<endl;
	cin>>row>>col;

	init_matrix(arr,row,col);
	print_the_matrix(arr,row,col);
	//to print the matrix in spiral form
	cout<<"Print in the spiral form: "<<endl;
	print_in_spiral(arr,row,col);
	cout<<endl;


	return 0;
}
