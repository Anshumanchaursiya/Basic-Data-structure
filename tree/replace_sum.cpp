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


int replacesum(node* root){

	if(root == NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	
	int left_subtree_sum = replacesum(root->left);
	int right_subtree_sum = replacesum(root->right);


	int temp = root->data;
	root->data = left_subtree_sum+right_subtree_sum;
	return temp + root->data;

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
			//condition is necessary to prevent infinite loop
			if(!q.empty()){
				q.push(NULL);
			}
			
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
				;
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
			q.pop();
		}

		
	}

}

int main(){

	node* root = BuildTree();
	bfs_levelwise(root);
	replacesum(root);
	cout<<endl;
	bfs_levelwise(root);
	return 0;
}