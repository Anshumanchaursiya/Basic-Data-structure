#include<iostream>
#include <queue>
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


node* createTree(int *preorder,int *inorder,int s,int e){

	static int i = 0;
	//base case
	if(s>e){
		return NULL;
	}

	node* root = new node(preorder[i]);

	int index=-1;
    for(int j=s;s<=e;j++){
        if(inorder[j]==preorder[i]){
            index = j;
            break;
        }
    }


	i++;
	root->left = createTree(preorder,inorder,s,index-1);
	root->right = createTree(preorder,inorder,index+1,e);
	return root;

}

int main(){

	
	int preorder[] = {1,2,3,4,8,5,6,7};
	int inorder[] = {3,2,8,4,1,6,7,5};
	int size = sizeof(preorder)/sizeof(int);

	node* root = createTree(preorder,inorder,0,size-1);
	bfs_levelwise(root);
	cout<<endl;

	return 0;
}