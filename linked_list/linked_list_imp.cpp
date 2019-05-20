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

//to define the length of the linked list
int length(node* head){

	if(head == NULL){
		return 0;
	}

	int l=0;
	while(head != NULL){
		l+=1;
		head = head->next;
	}

	return l;
}


//pass pointer variable by reference not just copy of the pointer variable like node * head
void insertAthead(node* &head,int data){

	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertAtlast(node* &head,int data){

	node* temp = head;
	if(head == NULL){
		insertAthead(head,data);
		return;
	}

	

	while(temp->next!= NULL){
		temp = temp->next;
	}

	node* n = new node(data);
	temp->next = n;
	n->next = NULL;
}

void insertAtmiddle(node* &head,int data,int p){

	if(head == NULL || p==0){
		insertAthead(head,data);
		return;
	}

	if(p > length(head)){
		insertAtlast(head,data);
		return;
	}

	node* temp = head;
	for(int i=0;i<p-1;i++){
		temp = temp->next;
	}

	node* n = new node(data);
	n->next = temp->next;
	temp->next = n;
}


//deletoin of node
void deleteAthead(node* &head){

	if(head == NULL){
		return;
	}

	//head = head->next; // it can be do but 1st node is not deleted due to dynomic memory allocation
	node* temp = head;
	head = temp->next;
	delete temp;
	return;

}

void deleteAttail(node* &head){

	if(head == NULL){
		return;
	}

	if(head->next == NULL){
		head == NULL;
		return;
	}

	node* pre = head;
	node* temp = head->next;
	while(temp->next != NULL){
		temp = temp->next;
		pre = pre->next;
	}

	pre->next = NULL;
	delete temp;
	return;
}

void deleteAtmiddle(node* head,int pos){

	if(head == NULL){
		return;
	}

	if(head->next == NULL || pos == 1){
		deleteAthead(head);
		return;
	}

	node* prev_node = head;
	node* curr_node = head->next;

	for(int i=1;i<pos;i++){
		prev_node = curr_node;
		curr_node = curr_node->next;
	}

	prev_node->next = curr_node->next;
	delete curr_node;
	return;

}

//searching

bool search(node* head,int data){

	if(head == NULL){
		return false;
	}

	while(head!= NULL){
		if(head->data == data){
			return true;
		}

		head = head->next;
	}

	return false;
}

bool recsearch(node* head,int data){

	//base case
	if(head == NULL){
		return false;
	}


	//rec case
	if(head->data == data){
		return true;
	}

	recsearch(head->next,data);

}



//input a linked list 
//take a number and it converts into a linkedlist unless input number is -1
void buildlinkedlist(node* &head){

	int num;
	cout<<"tell me the list of number: \n";
	cin>>num;

	while(num!= -1){
		insertAtlast(head,num);
		cin>>num;
	}
	return;

}

void print(node* head){

	
	while(head!= NULL){
		cout<<head->data<<", ";
		head = head->next;
	}
	cout<<endl;
}

//linked list operator overloading
istream& operator>>(istream &is, node* &head){

	buildlinkedlist(head);
	return is;
}


int main(){

	node* head = NULL;
	insertAthead(head,5);
	insertAthead(head,3);
	insertAthead(head,2);
	insertAthead(head,1);
	insertAtmiddle(head,10,2);
	insertAtmiddle(head,15,3);
	insertAtlast(head,12);
	//deleteAthead(head);
	//deleteAttail(head);
	
	if(recsearch(head,13)){
		cout<<"found\n";
	}
	else{
		cout<<"not found\n";
	}
	print(head);
	cout<<endl<<length(head)<<endl;


	return 0;
}
