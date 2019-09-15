#include<iostream>
using namespace std;

bool isRowSafe(int board[][4],int row,int num){

	for(int j=0;j<4;j++){
		if(num==board[row][j]){
			return false;
		}
	}
	return true;

}

bool isColSafe(int board[][4],int col,int num){

	for(int i=0;i<4;i++){
		if(num==board[i][col]){
			return false;
		}
	}
	return true;

}

bool isBoxSafe(int board[][4],int row,int col,int num){

	//this formula is used only for 4*4 grid
	//for 9*9 --> row_start = row - row % 3
	int row_start = row - row % 2;
	int col_start = col - col % 2;
	int i=2,j=2;

	while(i--){
		while(j--){
			if(board[row_start][col_start] == num){
				return false;
			}
			col_start++;
		}
		j=2;
		row_start++;
	}
	return true;

}

bool CanPlaceNum(int board[][4],int row,int col,int num){

	//checking in row
	if(!isRowSafe(board,row,num)){
		return false;
	}

	//checking in col
	if(!isColSafe(board,col,num)){
		return false;
	}

	//checking in box
	if(!isBoxSafe(board,row,col,num)){
		return false;
	}

	return true;

}

bool sudokuSolver(int board[][4]){

	int row = -1;
	int col = -1;
	bool isEmpty = false;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){

			if(board[i][j]==0){
				//we got the incex of empty cell
				row = i;
				col = j;
				isEmpty = true;
				break;
			}
		}
		if(isEmpty){
			break;
		}
	}

	//it means sudoku is solved
	if(!isEmpty){
		return true;
	}

	//deciding which number can be placed in empty cell
	for(int num =1;num<=4;num++){

		if(CanPlaceNum(board,row,col,num)){
			board[row][col] = num;
			//recursion -->checking for other empty cell
			if(sudokuSolver(board)){
				return true;
			}

			//backtracking if remaining sudoku can not be solved
			board[row][col] = 0;
		}
		
	}

	//sudoku can not be solved
	return false;


}

int main(){


	int board[4][4]={{1,3,0,4},{2,0,3,1},{0,1,0,2},{4,0,1,0}};

	bool possible = sudokuSolver(board);
	if(possible){
		cout<<"Solved:->"<<endl;
		for(int i=0;i<4;i++){

			for(int j=0;j<4;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<endl<<"Not Possible"<<endl;
	}

	return 0;
}
