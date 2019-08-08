#include<iostream>
using namespace std;

int count=0;
int* p = &count;

void permute(char* ch,int pos){

	//static int count=0;
	if(ch[pos]=='\0'){
		(*p)++;
		cout<<ch<<endl;
		return;
	}

	for(int j=pos;ch[j]!='\0';j++){
		swap(ch[pos],ch[j]);
		permute(ch,pos+1);

		//backtracking
		swap(ch[pos],ch[j]);
	}

	
}

int main(){

	char ch[100];
	cin>>ch;
	cout<<"\nall permutation->"<<endl;
	permute(ch,0);
	cout<<endl<<"Total count: "<<count<<endl;

	return 0;
}