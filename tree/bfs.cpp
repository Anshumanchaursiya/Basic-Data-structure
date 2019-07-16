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

node* BiuldTree(){

	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	
	root->left = BiuldTree();
	root->right = BiuldTree();
	

	return root;

}

void printpre(node* root){

	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	printpre(root->left);
	printpre(root->right);

}

void bfs(node* root){

	if(root == NULL){
		return;
	}

	queue<node*> q;
	q.push(root);

	
	while(!q.empty()){
		node* temp = q.front();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		
		if(temp->right!=NULL){
			q.push(temp->right);
		}
		
		cout<<temp->data<<" ";
		q.pop();

	}

	return;
}

int main(){

	node* root = BiuldTree();
	//printpre(root);
	bfs(root);
	return 0;
}
