#include<iostream>
using namespace std;

template <typename T>
class Queue{
    struct Node{
        T data;
        Node* next;
    };
    Node* front;
    Node* rear;
    public:
        void enqueue(T d);
        void dequeue();
        void traverse();
        Queue();
};
template<typename T>
Queue<T>::Queue(){
    front=NULL;
    rear=NULL;
}

template<typename T> 
void Queue<T>::enqueue(T d){
    Node* temp=new Node;
    temp->data=d;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
    
}

template<typename T>
void Queue<T>:: dequeue(){
    Node* temp=front;
    front=front->next;
    delete temp;
}

template<typename T>
void Queue<T> ::traverse(){
    if(front==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}

int main(){
    Queue<int> s1;
    bool flag=true;
	int d;
	int ch;
	while(flag){
		
		cout<<"Enter choise:"<<endl;

		cout<< "1.enqueue \n"
			"2.dequeue \n"
			"3.print \n"
			"4.quit \n"<<endl;
		
		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter data: ";
				cin>>d;
				s1.enqueue(d);
				break;
			case 2:
				s1.dequeue();
				break;
			case 3:
				cout<<"Traversal:"<<endl;
				s1.traverse();
				break;
			case 4:
				flag=false;
				break;
			default:
				cout<<"Invalid input"<<endl;
				return 0;
		}
	}

    return 0;
}
