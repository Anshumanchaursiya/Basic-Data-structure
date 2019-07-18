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

class linkedlist{
public:
	//because it contain address of type node
	node* head;
	node* tail;
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

linkedlist flatten(node* root){

	linkedlist l;
	if(root == NULL){
		l.head = l.tail = NULL;
		return l;
	}
	else if(root->left == NULL and root->right == NULL){
		l.head = root;
		l.tail = root;
		return l;
	}
	else if(root->left == NULL and root->right != NULL){
		linkedlist rightll = flatten(root->right);
		root->right = rightll.head;

		//new head 
		l.head = root;
		l.tail = rightll.tail;
		return l;

	}
	else if(root->left != NULL and root->left == NULL){
		linkedlist leftll = flatten(root->left);
		leftll.tail->right = root;

		//new node
		l.head = leftll.head;
		l.tail = root;
		return l;
	}
	
	//both side are not NULL
	else{
		
		linkedlist leftll = flatten(root->left);
		linkedlist rightll = flatten(root->right);
		leftll.tail->right = root;
		root->right = rightll.head;

		//new head
		l.head = leftll.head;
		l.tail = rightll.tail;
		return l; 
	}

}

void print(linkedlist l){

	if(l.head == NULL and l.tail == NULL){
		return;
	}

	node* temp = l.head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->right;
	}
	cout<<endl;
	return;
}

int main(){

	node* root = build_bst();
	linkedlist l = flatten(root);
	node*temp = l.head;

    while(temp!=NULL){
        cout<< temp->data <<" --> ";
        temp = temp->right;
    }
	cout<<endl;

	return 0;
}