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

int sum(node* root){

	if(root == NULL){
		return 0;
	}

	int s1 = sum(root->left);
	int s2 = sum(root->right);
	return root->data + s1+s2;

}



int main(){

	node* root = BuildTree();
	cout<<"sum of all nodes: "<<sum(root)<<endl;


	return 0;
}