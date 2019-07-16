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

class pairs{
public:
	int height;
	int diameter;

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

pairs diameter_optimized(node* root){

	pairs p;
	if(root == NULL){
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	//int h1 = height(root->left);
	//int h2 = height(root->right);

	//otherwise
	pairs left = diameter_optimized(root->left);
	pairs right = diameter_optimized(root->right);

	p.height = 1+ max(left.height,right.height);
	p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));

	return p;
	

}

int main(){

	node* root = BuildTree();
	pairs p = diameter_optimized(root);
	cout<<"height: "<<p.height<<"\ndiamaeter: "<<p.diameter<<endl;

	return 0;
}