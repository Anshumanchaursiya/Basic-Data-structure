#include<iostream>
using namespace std;


class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		left = NULL;
	}

};

node* BuildTree(){

	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	
	root->left = BuildTree();
	root->right = BuildTree();

}

int countnode(node* root){

	if(root == NULL){
		return 0;
	}

	int c1 = countnode(root->left);
	int c2 = countnode(root->right);
	return 1 + c1+c2;

}



int main(){

	node* root = BuildTree();
	cout<<"Number of nodes: "<<countnode(root)<<endl;


	return 0;
}