#include<iostream>
using namespace std;

void printstring(int k,char* ch,int n){

	static int count=0;
	if(n==k){
		ch[n]='\0';
		cout<<ch<<endl;
		count++;
		return;
	}

	//if previous char is 1
	if(ch[n-1]=='0'){
		ch[n]='0';
		printstring(k,ch,n+1);

		ch[n]='1';
		printstring(k,ch,n+1);
	}

	//if previous char is 0
	if(ch[n-1]=='1'){
		ch[n]='0';
		printstring(k,ch,n+1);
	}

	//cout<<count<<endl;
	return;

}

void allstring(int k){

	if(k==0){
		return;
	}
	char ch[k];


	//when this string start from 1
	ch[0]='1';
	printstring(k,ch,1);
	
	//when this string start from 0
	ch[0]='0';
	printstring(k,ch,1);

	return;

}

int main(){

	int k;
	cin>>k;
	allstring(k);
	cout<<endl;

	return 0;
}