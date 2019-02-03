#include<iostream>
#include<cstring>

using namespace std;

int main(){	

	int startrow,startcol,endrow,endcol;
	int n,a=1,b=1,c=1,d=1;
	char pattern[100][100];

	cout<<"Enter the value of n: ";
	cin>>n;
	startrow = 0;
	endcol = n-1;
	endrow = n-1;
	startcol = 0;

	while(startrow<=endrow && startcol<=endcol){

		//start row
		if(a){
			for(int j=startcol;j<=endcol;j++){
				pattern[startrow][j] = '0';
			}
			a=0;
		}
		else{
			for(int j=startcol;j<=endcol;j++){
				pattern[startrow][j] = 'X';
			}
			a=1;
		}
		startrow++;

		//end col
		if(b){
			for(int i=startrow;i<=endrow;i++){
				//cout<<"Hii"<<endl;
				pattern[i][endcol] = '0';

				
			}

			b=0;
		}
		else{
			for(int i=startrow;i<=endrow;i++){
				pattern[i][endcol] = 'X';
			}
			b=1;
		}
		endcol--;

		//end row
		if(c){
			for(int j=endcol;j>=startcol;j--){
				pattern[endrow][j] = '0';
			}
			c=0;
		}
		else{
			for(int j=endcol;j>=startcol;j--){
				pattern[endrow][j] = 'X';
			}
			c=1;
		}
		endrow--;

		//start col
		if(d){
			for(int i=endrow;i>=startrow;i--){
				pattern[i][startcol] = '0';
			}
			d=0;
		}
		else{
			for(int i=endrow;i>=startrow;i--){
				pattern[i][startcol] = 'X';
			}
			d=1;
		}
		startcol++;

	}	

	
	//for printing
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<" "<<pattern[i][j];
		}
		cout<<endl;
	}

	return 0;
}
