#include <iostream>
using namespace std;

template <class T>
class cNode{
public:
   cNode<T>* next;
   T data;
};

template <class T>
class cLinkedList{
public:
   cLinkedList(T elem){
      size=1;
      cNode<T>* node=new cNode<T>;
      node->data=elem;
      node->next=NULL;
      head=node;
      tail=node;
      cout<<"Created Object > called constructor > size of list : 1"<<endl;
      cout<<"Initialized with head value : "<<elem<<endl;
   }

   void push(T elem){
      cNode<T>* newNode = new cNode<T>;
      newNode->data=elem;
      newNode->next=head;
      tail->next=newNode;
      tail=newNode;
      size++;
      cout<<"\npushed : "<<elem<<" new size : "<<size<<endl;
   }

   void pop(){
      cNode<T>* old=head;
      int popped = old->data;
      head=head->next;
      tail->next=head;
      free(old);
      --size;
      cout<<"\npopped : "<<popped<<" new size : "<<size<<endl;
   }

   void show(){
      cout<<"\nCircular list : ";
      int count=size;
      cNode<T>* view = new cNode<T>;
      view=head;
      while(count>0){
         cout<<view->data<<"  ";
         view=view->next;
         count--;
      }cout<<endl;
   }

   void search(T elem){
      cout<<"\nSearching for Element : "<<elem<<endl;
      int count=size;
      bool flag = false;
      cNode<T>* temp = new cNode<T>;
      temp=head;
      while(count>0){
         if(temp->data==elem){
            cout<<"Element "<<elem<<" found at position "<<size-count+1<<endl;
            return;
         }
         temp=temp->next;
         --count;
      }
      cout<<"Element "<<elem<<" not found in list!!!"<<endl;
   }

   void reverse(){
      cout<<"\nReversing the Circular List Now"<<endl;
      T arr[size];
      int count=size;
      cNode<T>* temp = head;
      while(count>0){
         arr[size-count]=temp->data;
         temp=temp->next;
         --count;
      }
      count=size-1;
      temp=head;
      while(count>=0){
         temp->data=arr[count];
         temp=temp->next;
         --count;
      }
      cout<<"Reversal Successfull"<<endl;
   }

private:
   int size;
   cNode<T>* head;
   cNode<T>* tail;
};

int main(){
   cLinkedList<int> ob(5);
   for(int i=0;i<10;i++)
      ob.push(4*i);
   ob.show();
   ob.reverse();
   ob.show();
   for(int i=0;i<4;i++)
      ob.pop();
   ob.show();
   ob.search(24);
   ob.search(8);
   ob.search(32);
   ob.show();
   ob.reverse();
   ob.show();

}
