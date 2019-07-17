#include<iostream>
#include<queue>
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

void bfs_levelwise(node* root){

	if(root == NULL){
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();

		if(temp == NULL){
			cout<<endl;
			q.pop();
			//condition is necessary to prevent infinite
			if(!q.empty()){
				q.push(NULL);
			}
			
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
				
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
			q.pop();
		}

		
	}

}

void print_inorder(node* root){

	if(root == NULL){
		return;
	}

	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}

int main(){

	node* root = build_bst();
	bfs_levelwise(root);
	cout<<endl;
	print_inorder(root);
	cout<<endl;

	return 0;
}