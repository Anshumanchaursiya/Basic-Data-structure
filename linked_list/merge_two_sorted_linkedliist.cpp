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

void insertattail(node* &head,int d){

	node* temp = head;
	node* n = new node(d);
	if(head==NULL){
		
		head = n;
		n->next = NULL;
		return;
	}

	
	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = n;
	n->next = NULL;
	return;
}

node* buildlinkedlist(node*& head){

	int d;
	cin>>d;
	while(d!=-1){
		insertattail(head,d);
		cin>>d;
	}

	return head;
}

void print(node* head){
	cout<<head->data<<endl;
	if(head==NULL){
		cout<<"hi";
		return;
	}

	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	return;
}

node* merge_two_sorted_linkedlist(node* head1,node* head2){

	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}

	node* c;
	if(head1->data < head2->data){
		c = head1;
		c->next = merge_two_sorted_linkedlist(head1->next,head2);
	}
	else if(head2->data < head1->data){
		c = head2;
		c->next = merge_two_sorted_linkedlist(head1,head2->next);
	}

	return c;
}

int main(){
 
	node* head1 = NULL;
	node* head2 = NULL;
	cout<<"input two sorted array:\n";
	head1 = buildlinkedlist(head1);
	head2 = buildlinkedlist(head2);
	cout<<"1st linked list: ";
	print(head1);
	cout<<"\n2nd linked list: ";
	print(head2);
	node* newhead = merge_two_sorted_linkedlist(head1,head2);
	cout<<"\nmerged linked list: ";
	print(newhead);
	cout<<endl;
	return 0;
}