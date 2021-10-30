#include<iostream>

#define SIZE 10

using namespace std;

template<typename T>
class CirQueue{
    int s;
    T ar[SIZE];
    int front;
    int rear;
    public:
        CirQueue();
        void enqueue(T d);
        void dequeue();
        bool isEmpty();
        bool isFull();
        void print();
};

template<typename T>
CirQueue<T>::CirQueue(){
    front=rear=-1;
    s=SIZE;
}

template<typename T>
void CirQueue<T>::enqueue(T d){
    if(this->isFull())
        cout<<"Overflow"<<endl;
    else
    {
        if(rear==s-1&&front!=0)
        {
            rear=0;
            ar[rear]=d;
        }
        else
            ar[++rear]=d;
        if(front==-1&&rear==0)
            front=0;
    }
}

template<typename T>
void CirQueue<T>::dequeue(){
    if(this->isEmpty())
        cout<<"Underflow"<<endl;
    else
    {
         if(front==rear)
        {
            ar[front]=0;
            front=rear=-1;
        }
        else if(front==s-1)
        {
            ar[front]=0;
            front=0;
        }
        else
            ar[front++]=0;
       
        
    }
    
}

template<typename T>
bool CirQueue<T>::isEmpty(){
    if(front==rear==-1)
        return true;
    else
    {
        return false;
    }
    
}

template<typename T>
bool CirQueue<T>::isFull(){
    if(rear==front-1||(front==0&&rear==s-1))
        return true;
    else
    {
        return false;
    }
    
}

template<typename T>
void CirQueue<T>::print(){
    
    if(rear<front){
        for(int i=front;i<s;i++)
        {
            cout<<ar[i]<<endl;
        }
        for(int i=0;i<=rear;i++)
            cout<<ar[i]<<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<ar[i]<<endl;
        }
    }
    
}

int main(){
    CirQueue<int> s1;
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
				s1.print();
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
