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

node* search(node* root,int d){

	if(root == NULL){
		return NULL;
	}

	if(root->data == d){
		return root;
	}

	if(d<root->data){
		return search(root->left,d);
	}
	else{
		return search(root->right,d);
	}

}
	

node* delete_in_bst(node* root,int key){

	//if root is empty
	if(root == NULL){
		return NULL;
	}

	if(root->data == key){
		//1. if this node is leaf node
		node* key_ptr;
		if(key_ptr->left == NULL and key_ptr->right == NULL){
			return NULL;
		}

		//2. if this node has 1 child
		else if(key_ptr->left != NULL and key_ptr->right == NULL){
			return root->left;
		}
		else if(key_ptr->left == NULL and key_ptr->right != NULL){
			return root->right;
		}
 		
 		//3. if this node has 2 child
		else{

			node* replace = key_ptr;
			
			//replace min element of right subtree with key_ptr->data
			while(replace->left!=NULL){
				replace = replace->left;
			}	

			key_ptr->data = replace->data;

			delete replace;
		}
	}

	else if(key < root->data){
		root->left =  delete_in_bst(root->left,key);
	}
	else{
		root->right =  delete_in_bst(root->right,key);
	}

	return root;
}

int main(){

	int key;
	node* root = build_bst();
	cout<<endl<<"inorder traversal of tree: ";
	print_inorder(root);
	cout<<endl<<"enter the key you want to delete: ";
	cin>>key;
	delete_in_bst(root,key);
	print_inorder(root);
	cout<<endl;

	return 0;
}