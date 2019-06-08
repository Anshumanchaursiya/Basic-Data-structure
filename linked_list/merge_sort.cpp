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

int length(node* head){

	if(head==NULL){
		return 0;
	}
	int l=0;
	while(head!=NULL){
		head=head->next;
		l++;
	}
	return l;
}

node* midpoint(node* head){
	
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* slow = head;
	node* fast;
	if(length(head)&1){
		fast = head;
	}
	else{
		fast = head->next;
	}

	while(fast->next != NULL and fast!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		
	}

	return slow;
}

node* mergeSort(node* &head){

	
	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}

	//rec case
	// 1. mid point
	node* mid = midpoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	// 2. sort a and b
	node* a1 = mergeSort(a);
	node* b2 = mergeSort(b);

	// 3. merge a and b
	node* c = merge_two_sorted_linkedlist(a1,b2);

	return c;
}

int main(){
 
	node* head = NULL;
	cout<<"input unsorted array:\n";
	head = buildlinkedlist(head);
	print(head);
	node* newhead = mergeSort(head);
	cout<<"\nsorted Linkedlist: ";
	print(newhead);
	cout<<endl;
	return 0;
}