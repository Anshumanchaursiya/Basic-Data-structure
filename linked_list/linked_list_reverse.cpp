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
	n->next = head;
	head = n;
}

void print(node* head){

	if(head == NULL){
		cout<<"empty linked list";
		return;
	}

	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}

	return;
}

void reverse(node* &head){

	node* c = head;
	node* p = NULL;
	node* n;

	while(c!=NULL){
		//save the address of current ka next
		n = c->next;
		c->next = p;
		p = c;
		c = n; 
	}

	head = p;

	return;

}

int main(){

	node* head = NULL;

	insertathead(head,3);
	insertathead(head,4);
	insertathead(head,5);
	insertathead(head,6);
	print(head);
	cout<<"\nReverse linked list"<<endl;
	reverse(head);
	print(head);
	cout<<endl;

	return 0;
}
