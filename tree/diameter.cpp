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

int height(node* root){

	if(root==NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1 + max(h1,h2);
}

int diameter(node* root){

	if(root == NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	//cout<<"op1: "<<op1<<endl<<"op2: "<<op2<<endl<<"op3: "<<op3<<endl;
	return max(op1,max(op2,op3));
}

int main(){

	node* root = BuildTree();
	cout<<"diameter: "<<diameter(root)<<endl;

	return 0;
}