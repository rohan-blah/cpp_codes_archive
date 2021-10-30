#include<bits/stdc++.h>
using namespace std;

#define SIZE 20

template<typename T>
class Stack{
    private:
        T ar[SIZE];
        int top;
    public:
        void push(T d);
        void pop();
        Stack();
        bool isEmpty();
        bool isFull();
        void traverse();

};
template<typename T>
bool Stack<T>::isEmpty(){
    if(top==-1)
        return true;
    else
    {
        return false;
    }
}
template<typename T>
bool Stack<T>::isFull(){
    if(top==SIZE)
        return true;
    else
    {
        return false;
    }
    
}

template<typename T>
void Stack<T>::push(T d){
    if(!isFull()){
        ar[++top]=d;
    }
    else
    {
        cout<<"Overflow"<<endl;
    }
    
}
template<typename T>
void Stack<T>::pop(){
    if(!isEmpty()){
        ar[top--]=0;
    }
    else
    {
        cout<<"Underflow"<<endl;
    }
    
}
template<typename T>
Stack<T>::Stack(){
    top=-1;
}
template<typename T>
void Stack<T>::traverse(){
	int temp=top;
    while(temp!=-1){
        cout<<ar[temp--]<<" ";
    }
    cout<<endl;
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
			"3.traverse \n"
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
