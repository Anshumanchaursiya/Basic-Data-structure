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
		right = NULL;
	}

}; 


//this is preorder implementation
node* BuildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* root = new node(d);
	root->left = BuildTree();
	root->right = BuildTree();

	return root;
}


void print(node* root){

	if(root == NULL){
		return;
	}

	 //Otherwise, print root first followed by subtrees(children)
	cout<<root->data<<" ";

	print(root->left);
	print(root->right);

	return;
}

//Inorder printing of tree
void printIn(node* root){

	if(root == NULL){
		return;
	}

	//otherwise print left root right
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);

	return;

}

//Postorder printing of tree
void printPost(node* root){

	if(root == NULL){
		return;
	}

	//otherwise print left right root
	printPost(root->left);
	
	printPost(root->right);
	cout<<root->data<<" ";

	return;

}


int main(){

	node* root = BuildTree();
	cout<<"Preorder-> ";
	print(root);
	cout<<endl<<"Inorder-> ";
	printIn(root);
	cout<<endl<<"Postorder-> ";
	printPost(root);
	cout<<endl;

	return 0;
}