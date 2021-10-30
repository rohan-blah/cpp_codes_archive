#include <iostream>
using namespace std;

class pNode{
public:
   int degree;
   int coefficient;
   pNode* next;
};

class polynomial{
public:
   polynomial(int c,int d){
      pNode* newNode = new pNode;
      newNode->coefficient=c;
      newNode->degree=d;
      newNode->next=NULL;
      head=newNode;
      size=1;
      char ch='y';
      while(ch=='y' || ch=='Y'){
         cout<<"\nmore node?('y'/'n') : ";
         cin>>ch;
         if(ch=='Y' || ch=='y')
            head=nextNode(head);
      }
   }

   polynomial(polynomial p1,polynomial p2){
      pNode* p1_head = p1.head;
      pNode* p2_head = p2.head;
      pNode* big;
      pNode* small;
      pNode* p3 = new pNode;
      size=0;
      if(p1.getSize()<=p2.getSize()){
         small=p1_head;
         big=p2_head;
      }else{
         small=p2_head;
         big=p1_head;
      }

      while(big!=NULL){
         if(small==NULL){
            while(big!=NULL){
               pNode* newNode = new pNode;
               newNode->coefficient = big->coefficient;
               newNode->degree = big->degree;
               if(size==0){
                  p3=newNode;
                  head=p3;
               }
               else{
                  p3->next=newNode;
                  p3=p3->next;
               }
               size++;
            }
            size++;
         }
         if(big->degree>small->degree){
            pNode* newNode = new pNode;
            newNode->coefficient=big->coefficient;
            newNode->degree=big->degree;
            newNode->next=NULL;
            if(size==0){
               p3=newNode;
               head=p3;
            }
            else{
               p3->next=newNode;
               p3=p3->next;
            }
            big=big->next;
            size++;
         }
         else if(big->degree==small->degree){
            pNode* newNode = new pNode;
            newNode->coefficient = big->coefficient+small->coefficient;
            newNode->degree = big->degree;
            newNode->next=NULL;
            if(size==0){
               p3=newNode;
               head=p3;
            }
            else{
               p3->next=newNode;
               p3=p3->next;
            }
            size++;
            big=big->next;
            small=small->next;
         }
         else if(big->degree<small->degree){
            pNode* newNode = new pNode;
            newNode->coefficient=small->coefficient;
            newNode->degree=small->degree;
            newNode->next=NULL;
            if(size==0){
               p3=newNode;
               head=p3;
            }
            else{
               p3->next=newNode;
               p3=p3->next;
            }
            small=small->next;
            size++;
         }
      }

   }

   pNode* nextNode(pNode* p){
      pNode* newNode = new pNode;
      pNode* newP = p;
      cout<<"Enter coefficient : ";
      cin>>newNode->coefficient;
      cout<<"Enter degree : ";
      cin>>newNode->degree;
      pNode* temp = new pNode;
      temp = p;
      int s = getSize();
      while(s>0){
         if(temp->degree==newNode->degree){
            temp->coefficient+=newNode->coefficient;
            return newP;
         }
         temp=temp->next;
         s--;
      }
      if(p->degree<newNode->degree){
         newNode->next=p;
         p=newNode;
         size++;
         return p;
      }
      temp = p;
      while(p->degree>newNode->degree && p->next!=NULL){
         temp=p;
         p=p->next;
      }
      if(p->next==NULL){
         newNode->next=p->next;
         p->next=newNode;
      }
      size++;
      return newP;
   }

   void show(){
      pNode* view = new pNode;
      view=head;
      cout<<"\nPolynomial : ";
      if(view==NULL) cout<<"head null";
      while (view!=NULL) {
         if(view->coefficient!=0){
            cout<<view->coefficient;
            if(view->degree!=0){
               cout<<"*"<<"(x^"<<view->degree<<")";

            }
            if(view->next!=NULL){
               cout<<"  +  ";
            }
         }
         view=view->next;
      }cout<<"  =  0";

      cout<<endl<<endl;

   }

   int getSize(){
      return size;
   }
private:
   pNode* head;
   int size;
};

int main(){
   int coeff,deg;

   cout<<"Initializing p1\n";
   cout<<"Enter coefficient : ";
   cin>>coeff;
   cout<<"Enter degree : ";
   cin>>deg;

   polynomial p1(coeff,deg);
   p1.show();

   cout<<"Initializing p2\n";
   cout<<"Enter coefficient : ";
   cin>>coeff;
   cout<<"Enter degree : ";
   cin>>deg;

   polynomial p2(coeff,deg);
   p2.show();

   cout<<"Want to add two polynomials : ";
   char ch;
   cin>>ch;

   if(ch=='y' || ch=='Y'){
      cout<<"polynomial 1 : ";
      p1.show();
      cout<<"polynomial 2 : ";
      p2.show();
      polynomial p3(p1,p2);
      cout<<"new polynomial after adding polynomial 1 and polynomial 2 : ";
      p3.show();
   }

}
