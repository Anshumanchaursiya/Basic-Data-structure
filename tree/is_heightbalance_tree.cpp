#include<iostream>
#include <cstdlib>
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

class HBpair{
public:
	int height;
	bool B;

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

HBpair isHeightbalance_tree(node* root){

	HBpair hb;

	if(root == NULL){
		hb.B = true;
		hb.height = 0;
		return hb;
	}

	if(root->left == NULL and root->right == NULL){
		hb.B = true;
		hb.height = 1;
		return hb;
	}

	HBpair left = isHeightbalance_tree(root->left);
	HBpair right = isHeightbalance_tree(root->right);
	int diff = std::abs(left.height-right.height);

	if(diff<=1 and left.B == true and left.B == true){
		hb.height = max(left.height,right.height)+1;
		hb.B = true;
		return hb;
	}
	else{
		hb.height = max(left.height,right.height)+1;
		hb.B = false;
		return hb;
	}

}

int main(){

	node* root = BuildTree();
	HBpair hb = isHeightbalance_tree(root);
	if(hb.B){
		cout<<"height Balance tree"<<endl;
	}
	else{
		cout<<"not Balance"<<endl;
	}

	return 0;
}