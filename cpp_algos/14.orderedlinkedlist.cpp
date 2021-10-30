#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int d){
			data=d;
			next=NULL;
		}
		node(){
			next=NULL;
		}
};

class list{
	public:
		node* head;
		node* merge(node* n1,node* n2);
		void sortedInsert(int);
		void deletenode(int pos);
		void traverse();
		list(){head=NULL;}
};

void list::deletenode(int pos){
	if(pos==1){
		if(head==NULL){
			cout<<"Invalid position entered"<<endl;
			exit(0);
		}
		node* temp=head;
		head=head->next;
		delete(temp);
	}
	else
	{
		node* temp=head;
		for(int i=2;i<pos;i++)
			temp=temp->next;
		
		node* temp1=temp->next;
		if(temp1==NULL){
			cout<<"Invalid position entered"<<endl;
			exit(0);
		}
		if(temp1->next==NULL){
			temp->next=NULL;
			delete(temp1);
		}
		else{
			temp->next=temp->next->next;
			delete(temp1);
		}

	}
}


void list::sortedInsert(int X)
{
	node* temp=head;
	
	if(temp==NULL)
	{
		temp = new node;
		temp->data = X;
		temp->next = NULL;
		head=temp;
	}
	
	else
	{
		
		if(X < temp->data) 
		{
			node* t = new node;
			t->data = X;
			t->next = head;
			head = t;
		}
			
		else
		{
			while(temp->next != NULL and !(X < temp->next->data && X >= temp->data)) 
				temp=temp->next;
			
			if(temp->next == NULL) 
			{
				temp->next = new node;
				temp = temp->next;
				temp->data = X;
				temp->next = NULL;
			}
			else 
			{
				node* t = new node;
				t->data = X;
				t->next = temp->next; 
				temp->next = t;
			}
		}
	}
}

void list::traverse(){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

node* list::merge(node* n1,node* n2){
	node* temp=NULL;
	node* head=NULL;
	while(n1!=NULL&&n2!=NULL){
		if(temp==NULL)
			temp=new node();
		else
		{
			temp->next=new node();
			temp=temp->next;
		}
		if(head == NULL)
			head = temp;

		if(n1->data<n2->data){
			temp->data=n1->data;
			n1=n1->next;
		}
		else
		{
			temp->data=n2->data;
			n2=n2->next;
		}
	}
	while(n1!=NULL){
		temp->next=new node();
		temp=temp->next;
		temp->data=n1->data;
		n1=n1->next;
	}
	while(n2!=NULL){
		temp->next=new node();
		temp=temp->next;
		temp->data=n2->data;
		n2=n2->next;
	}
	return head;
}

int main(){
	list l1;
	list l2;
	list l3;
	bool flag=true;
	int d;
	int e;
	int ch;
	while(flag){
		
		cout<<"Enter choise:"<<endl;

		cout<< "1.insert \n"
			"2.delete \n"
			"3.merge \n"
			"4.traverse \n"
			"5.quit \n"<<endl;
		
		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter data for list1 and list2: ";
				cin>>d;
				cin>>e;
				l1.sortedInsert(d);
				l2.sortedInsert(e);
				break;
			case 2:
				cout<<"Enter position of deletion for list1 and list2: ";
				cin>>d;
				cin>>e;
				l1.deletenode(d);
				l2.deletenode(e);
				break;
			case 3:
				l3.head=l3.merge(l1.head,l2.head);
				l3.traverse();
				break;
			case 4:
				cout<<"Traversal:"<<endl;
				l1.traverse();
				l2.traverse();
				break;
			case 5:
				flag=false;
				break;
			default:
				cout<<"Invalid input"<<endl;
				return 0;
		}
	}

	return 0;
}
