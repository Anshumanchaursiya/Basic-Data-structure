#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertathead(node* &head,int data){

	node* n = new node(data);
	if(head==NULL){
		head = n;
		n->next=NULL;
		return;
	}

	n->next = head;
	head = n;
	return;
}

void buildlinked_list(node* &head){

	int n;
	cout<<"tell the list of number: ";
	cin>>n;
	while(n!=-1){
		insertathead(head,n);
		cin>>n;
	}
	return;
}


void print(node*head){
	if(head==NULL){
		cout<<"empty list";
		return;
	}

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;

	return;
}


node* reverselinkedlist_recursion(node* head){

	//base case
	if(head==NULL || head->next==NULL){
		return head;
	}

	//recursive case
	node* smallhead = reverselinkedlist_recursion(head->next);
	node* c = head;
	c->next->next = c;
	c->next  = NULL;

	return smallhead;
}

int main(){

	node* head = NULL;
	buildlinked_list(head);
	print(head);
	node* newhead = reverselinkedlist_recursion(head);
	print(newhead);

	return 0;
}