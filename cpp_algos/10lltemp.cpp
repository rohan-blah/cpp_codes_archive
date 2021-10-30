#include<iostream>
using namespace std;

template<typename t>
struct node{
	t data;
	node* next;
};

node<int>* head1=NULL;
node<int>* head2=NULL;

template<typename t>
void insert(int pos,t data,node<t>* &head){
	if(pos==1){
		node<t>* temp=new node<int>();
		temp->data=data;
		if(head==NULL){
			temp->next=NULL;
			head=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
		

	}
	else
	{
		node<t>*temp=head;
		for(int i=2;i<pos;i++){
			temp=temp->next;
			if(temp==NULL){
				cout<<"Invalid pos"<<endl;
				exit(0);
			}
		}
		node<t>* temp1=new node<t>();
		temp1->data=data;
		if(temp->next==NULL){
			temp->next=temp1;
			temp1->next=NULL;
		}
		else{
			temp1->next=temp->next;
			temp->next=temp1;
		}
	}
}

template<typename t>
void traverse(node<t>* head){
	node<t>* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

template<typename t>
void deletenode(int pos,node<t>*&head){
	if(pos==1){
		if(head==NULL){
			cout<<"Invalid position entered"<<endl;
			exit(0);
		}
		node<t>* temp=head;
		head=head->next;
		delete(temp);
	}
	else
	{
		node<t>* temp=head;
		for(int i=2;i<pos;i++)
			temp=temp->next;
		
		node<t>* temp1=temp->next;
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

template<typename t>
t search(t data,node<t>* head){
	int c=1;
	node<t>* temp=head;
	while(temp!=NULL){
		if(temp->data==data)
			return c;
		temp=temp->next;
		c++;
	}
	return -1;
}

template<typename t>
void reverse(node<t>* temp,node<t>*& head){
	if(temp==NULL){
		return;
	}
	else
	{
		bool ishead=false;
		if(temp==head)
			ishead=true;
		node<t>* tempnode=temp->next;
		reverse(temp->next,head);
		if(tempnode==NULL)
			head=temp;
		else{
			tempnode->next=temp;
		}
		if(ishead)
			temp->next=NULL;
	}
	
}

template<typename t>
node<t>* operator+(node<t>& n1,node<t>& n2){
	node<t>* t1=&n1;
	node<t>* t2=&n2;
	node<t>* temp=t1;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=t2;
	
	return t1;
}

int main(){
	insert(1,20,head1);
	insert(2,40,head1);
	insert(1,10,head1);
	insert(3,30,head1);
	insert(5,50,head1);
	insert(6,60,head1);
	
	insert(1,70,head2);
	insert(2,80,head2);
	insert(3,90,head2);
	traverse<int>(head1);traverse<int>(head2);
	*head1+(*head2);
	traverse<int>(head1);
	reverse(head1,head1);
	traverse<int>(head1);
	cout<<search(30,head1)<<" "<<search(60,head1)<<" "<<search(10,head1)<<" "<<search(100,head1)<<endl;
	deletenode<int>(6,head1);
	deletenode<int>(3,head1);
	deletenode<int>(1,head1);
	traverse<int>(head1);
	
	
	return 0;
}
