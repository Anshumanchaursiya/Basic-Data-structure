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


//this is preorder implementation
node* BuildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* root = new node(d);
	root->left = BuildTree();
	root->right = BuildTree();

	return root;
}


void print(node* root){

	if(root == NULL){
		return;
	}

	 //Otherwise, print root first followed by subtrees(children)
	cout<<root->data<<" ";

	print(root->left);
	print(root->right);

	return;
}

//Inorder printing of tree
void printIn(node* root){

	if(root == NULL){
		return;
	}

	//otherwise print left root right
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);

	return;

}

//Postorder printing of tree
void printPost(node* root){

	if(root == NULL){
		return;
	}

	//otherwise print left right root
	printPost(root->left);
	
	printPost(root->right);
	cout<<root->data<<" ";

	return;

}

int Height(node* root){

	if(root == NULL){
		return 0;
	}

	int Heightof_left_sub_tree = Height(root->left);
	int Heightof_right_sub_tree = Height(root->right);

	return max(Heightof_left_sub_tree,Heightof_right_sub_tree) + 1;
}

void Print_kth_level(node* root,int k){

	if(root == NULL){
		return;
	}

	if(k==1){
		cout<<root->data<<" ";
		return;
	}

	Print_kth_level(root->left,k-1);
	Print_kth_level(root->right,k-1);
	return;
}

void Print_all_level(node* root){

	if(root == NULL){
		return;
	}

	int H = Height(root);

	for(int i=1;i<=H;i++){
		Print_kth_level(root,i);
		cout<<endl;
	}

	return;
}

int main(){

	node* root = BuildTree();
	cout<<"Preorder-> ";
	print(root);
	cout<<endl<<"Inorder-> ";
	printIn(root);
	cout<<endl<<"Postorder-> ";
	printPost(root);
	cout<<endl;
	cout<<"Height = "<<Height(root)<<endl;
	//cout<<"print kth level = ";
	//Print_kth_level(root,2);
	Print_all_level(root);
	cout<<endl;

	return 0;
}