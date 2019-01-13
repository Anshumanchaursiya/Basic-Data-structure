#include<iostream>
using namespace std;

//self referencial class
class node{
public:
	int data;
	node* next;

	//constructor
	node(int d){
		data = d;
		next = NULL; 
	}

};




int lenth(node* head){
	int len=0;
	while(head!=NULL){
		head=head->next;
		len+=1;
	}

	return len;
}

//Passing a pointer variable through refer
void insertAtHead(node* &head,int data){
	node *n = new node(data);
	n->next = head;
	head = n;
}



//insert the data at the last node
void insetAtTail(node* &head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}

	node* tail = head;
	while(tail->next!=NULL){
		tail = tail->next;
	}
	tail->next = new node(data);
	return;
}



//Inserting the node at the middle
void insertAtMiddle(node* &head,int data,int p){
	if(head==NULL || p==0){
		insertAtHead(head,data);

	}
	
	else if(p>lenth(head)){
			insetAtTail(head,data);

		}
	
	//insert in the middle 
	//first take p-1 jump
	else{
		int jump=0;
		node* temp = head;
		while(jump<=p-1){   
			temp=temp->next;
			jump+=1;
		}
	}

	//creating the new node to insert at the given position p
	node* temp = head;
	node* n = new node(data);
	n->next = temp->next;
	temp->next = n;


}


void printNode(node *head){
	//node* temp;
	//temp = head;
	while(head != NULL){
		cout<<head->data;
		head = head->next;
		cout<<" ";

	}
	
}

//for deletion of the node

void deleteAtHead(node* &head){
	if(head!=NULL){
		node* temp = head;
		head = head->next;
	}
	
}

/*

void deleteInTheMiddle(node* & head,int pos){
	if(head==NULL){
		return;	
	}


	if(pos==0){
		deleteAtHead(head);
	}

	else{
		node* n = head;
		node* temp;
		int jp=0;
		while(jp<=pos){
			n=n->next;
			temp=temp->next;
			jp+=1;
			if(jp==pos-1){
				cout<<"Your position is correct"<<endl;
				temp = temp->next->next;
				n->next = temp->next;
				
			}
		}


	}


}

*/


void deleteInTheMiddle(node* & head,int pos){
	if(head==NULL){
		return;	
	}


	if(pos==0){
		deleteAtHead(head);
	}

	else{
		node* n = head->next;
		node* temp = head;
		int jp=0;
		while(jp<=pos){
		
			if(jp==pos-1){
				temp->next = n->next;
			}
			jp++;
		}


	}


}


void deleteAtTail(node* head){
	if(head==NULL){
		return;
	}

	int jump=0;
	node* temp = head;
	while(head!=NULL){
		temp = temp->next;
		if(temp->next == NULL){
			head->next = temp->next;
			return;
		}
		head = head->next;

	}
}



bool search(node* &head,int search_no){  //why here we are passing by value , why not we are passing by reference
	//base case
	if(head==NULL){
		return false;		
	}

/*
	while(head!=NULL){
		head = head->next;
		if(head->data == search_no){
			return true;
		}
	}
	return false;

*/
	//recursive case
	if(head->data == search_no){
		return true;
	}

	search(head->next,search_no);

}


void reverse(node* &head){
	node* n;
	node* c=head;
	node* p=NULL;

	while(c!=NULL || n!= NULL){
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}


int main(){
	node* head;
	head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,8);
	insertAtHead(head,10);
	//insertAtMiddle(head,11,2);
	insetAtTail(head,23);

	//cout<<endl<<search(head,10)<<endl;
	//deleteAtHead(head);
	deleteInTheMiddle(head,2);
	//deleteAtTail(head);
	//reverse(head);
	printNode(head);
	
	cout<<endl;


	return 0;
}
