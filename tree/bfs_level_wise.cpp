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

	return 0;
}