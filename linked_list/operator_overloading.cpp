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



void insert_at_head(node*& head,int data){

	node* n = new node(data);
	n->next = head;
	head = n;
}


void insert_at_tail(node*&head,int data){
	node* temp = head;
	if(head==NULL){
		insert_at_head(head,data);
		return;
	}

	while(temp->next!=NULL){
		cout<<"hi"<<endl;
		temp = temp->next;
	}
	node* n = new node(data);
	temp->next = n;
	n->next = NULL;


	return;
}

node* build_list(node*& head){
	int data;
	cin>>data;
	while(data!=-1){
		insert_at_tail(head,data);
		cin>>data;
	}

	return head;
}

void print_list(node* head){
	if(head==NULL){
		cout<<"empty list";
		return ;
	}

	while(head!=NULL){
		cout<<head->data<<"-> ";
		head = head->next;
	}
	return;

}

//operator overloading

istream& operator>>(istream& is,node*& head){
	build_list(head);
	return is;
}

ostream& operator<<(ostream& os,node*& head){
	print_list(head);
	return os;
}

int main(){

	node* head = NULL;
	node* head2 = NULL;
	cin>>head>>head2;
	cout<<head<<endl<<head2;

	return 0;
}
