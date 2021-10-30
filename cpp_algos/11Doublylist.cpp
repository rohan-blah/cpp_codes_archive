#include<iostream>
using namespace std;

template<typename t>
class node
{
    public:
        t data;     	
        node<t> *prev;  	
        node<t> *next; 	
};

template<typename t>
class Doubly_Linked_List
{
    public:
        node<t> *front;  	
        node<t> *end;   	
        Doubly_Linked_List()
        {
            front = NULL;
            end = NULL;
        }


        void insert(int ,t);
        void delete_node(int n);
        void forward_traverse();
        void backward_traverse();
        int search(t);
        void reverse(node<t>*);
};


template<typename t>
void Doubly_Linked_List<t> :: delete_node(int n)
{	
	node<t>* temp=front;
	for(int i=1;i<n;i++)
		temp=temp->next;

	if(temp->prev == NULL)
	{
		front = temp->next; 
		front->prev = NULL;
	}
	else if(temp->next == NULL)
	{
		end=temp->prev;
		end->next=NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	delete(temp);			
}

template<typename t>
void Doubly_Linked_List<t> :: forward_traverse()
{
	node<t> *trav;
	trav = front;
	while(trav != NULL)
	{
		cout<<trav->data<<" ";
		trav = trav->next;
	}
	cout<<endl;
}

template<typename t>
void Doubly_Linked_List<t> :: backward_traverse()
{
	node<t> *trav;
	trav = end;
	while(trav != NULL)
	{
		cout<<trav->data<<" ";
		trav = trav->prev;
	}
	cout<<endl;
}

template<typename t>
int Doubly_Linked_List<t>:: search(t data){
	int c=1;
	node<t>* temp=front;
	while(temp!=NULL){
		if(temp->data==data)
			return c;
		temp=temp->next;
		c++;
	}
	return -1;
}

template<typename t>
void Doubly_Linked_List<t>::reverse(node<t>* tempfront){
	if(tempfront==NULL){
		return;
	}
	else
	{
		node<t>* temp;
		node<t>* current=tempfront;
		while(current!=NULL){
			temp=current->prev;
			current->prev=current->next;
			current->next=temp;
			current=current->prev;
		}
		temp=front;
		front=end;
		end=temp;
	}
	
}

template<typename t>
void Doubly_Linked_List<t>:: insert(int pos,t d){
	if(pos==1){
		node<t> *temp;
        temp = new node<t>();
        temp->data = d;
        temp->prev = NULL;
        temp->next = front;

        if(front == NULL)
            end = temp;
            
        else
            front->prev = temp;

        front = temp;
	}
	else
	{
		node<t>*temp=front;
		for(int i=2;i<pos;i++){
			temp=temp->next;
			if(temp==NULL){
				cout<<"Invalid pos"<<endl;
				exit(0);
			}
		}
		node<t>* temp1=new node<t>();
		temp1->data=d;
		if(temp->next==NULL){
			temp1->prev = end;
            temp1->next = NULL;
            end->next = temp1;	
            end = temp1;
		}
		else{
			temp1->next=temp->next;
            temp1->prev=temp;
            temp->next->prev=temp1;
            temp->next=temp1;
		}
	}
}

int main(){
	bool flag=true;
	Doubly_Linked_List<int> l1;
	int d;
	int p;
	int ch;
	while(flag){
		
		cout<<"Enter choise:"<<endl;

		cout<< "1.insert_node \n"
			"2.delete_node \n"
			"3.forward_traverse \n"
			"4.backward_traverse \n"
			"5.search \n"
			"6.reverse \n"
			"7.quit \n"<<endl;
		
		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter position to insert the node: ";
				cin>>p;
				cout<<"Enter node->data: ";
				cin>>d;
				l1.insert(p,d);
				l1.forward_traverse();
				break;
			case 2:
				cout<<"Enter position of node to delete: ";
				cin>>p;
				l1.delete_node(p);
				l1.forward_traverse();
				break;
			case 3:
				l1.forward_traverse();
				break;
			case 4:
				l1.backward_traverse();
				break;
			case 5:
				cout<<"Enter data to search for: ";
				cin>>d;
				cout<<"Element searched is at index: "<<l1.search(d);
				break;
			case 6:
				l1.reverse(l1.front);
				l1.forward_traverse();
				break;
			case 7:
				flag=false;
				break;
			default:
				cout<<"Invalid input"<<endl;
				return 0;
		}
	}
    return 0;
}
