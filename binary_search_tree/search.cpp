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

node* insert_in_bst(node* root,int d){

	node* new_node = new node(d);
	if(root == NULL){
		return new_node;
	}

	if(d<=root->data){
		root->left = insert_in_bst(root->left,d);
	}
	else{
		root->right = insert_in_bst(root->right,d);
	}

	//returning new root(updated)
	return root;
}

node* build_bst(){

	int d;
	cin>>d;
	node* root = NULL;

	//taking input untill -1 is read 
	while(d!=-1){
		root = insert_in_bst(root,d);
		cin>>d;
	}
	return root;

}


void print_inorder(node* root){

	if(root == NULL){
		return;
	}

	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}

bool is_present(node* root,int d){

	if(root == NULL){
		return false;
	}

	if(root->data == d){
		return true;
	}

	if(d<root->data){
		return is_present(root->left,d);
	}
	else{
		return is_present(root->right,d);
	}

}

int main(){

	int key;
	node* root = build_bst();
	cout<<endl<<"inorder traversal of three: ";
	print_inorder(root);
	cout<<endl<<"enter the key: ";
	cin>>key;
	if(is_present(root,key)){
		cout<<"present"<<endl;
	}
	else{
		cout<<"not preesent"<<endl;
	}

	return 0;
}