#include<iostream>
using namespace std;

template<typename T>
class Stack{
	struct Node{
		T data;
		Node* next;
	};
	Node* top;
	public:
		void pop();
		void push(T d);
		T peek();
		Stack();
};

template<typename T>
Stack<T>::Stack(){
	top=NULL;
}

template<typename T>
void Stack<T>:: pop(){
	if(top==NULL)
		cout<<"Underflow"<<endl;
	else
	{
		Node* temp=top;
		top=top->next;
		delete temp;
	}
	
}

template<typename T>void Stack<T>:: push(T d){
	Node* temp=new Node();
	temp->data=d;
	temp->next=top;
	top=temp;
}

template<typename T>T Stack<T>::peek(){
	return top->data;
}

int main(){
	Stack<int> s1;
	bool flag=true;
	int d;
	int ch;
	while(flag){
		
		cout<<"Enter choise:"<<endl;

		cout<< "1.push \n"
			"2.pop \n"
			"3.peek \n"
			"4.quit \n"<<endl;
		
		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter data: ";
				cin>>d;
				s1.push(d);
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				cout<<s1.peek()<<" is at the top of stack"<<endl;
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
