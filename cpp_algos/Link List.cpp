#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode
{

 public:
    INntSLLNode()
    {
        next=0;
    }
    IntSLLNode(inti,IntSLLNode*in=0)
    {
        info=i;next=in;
    }
    int info;
    IntSLLNode *node;
};
class IntSLList{
public:
    InstSLList()
    {
     head=tail=0;
    }
    ~intSLList();
    int isEmpty()
    {

        return head==0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
private:
     IntSLLNode *head, *tail;

     };
#endif
//***************************intSLList.cpp***********************************************
#include<iostream>
#include "IntSLList.h"
IntSLList::~IntSLList()
{

     for (IntSLLNode *p; !isEmpty();)
     {

          p=head->next;
          delete head;
          head=p;

     }

}
void IntSLList::addToHead(int e1)
{
    head=new InstSLLNode(e1,head);
    if(tail==0)
        tail=head;
}
void IntSLList::addToTail(int e1)
{
    if(tail!=0)
    {
        tail->next=new IntSLLNode(e1);
        tail=tail->next;
    }
    else
        head=tail=new IntSLLNode(e1);
}
int IntSLList::deleteFromHead()
{
    int e1=head->info;
    IntSLLNode *temp=head;
    if(head==tail)
      head=tail=0;
     else
        head=head->next;
     delete temp;
     return e1;

}
int IntSLList::deleteFromTail()
{
    int e1=tail->info;
    if(head==tail)
    {

      delete head;
      head=tail=0;
    }
   else
   {
    IntSLLNode *temp;
    for(temp=head;tmp->next !=tails; temp=temp->next)
      delete tail;
    tail=temp;
    tail->next=0;

}
  return e1;
   }
void IntSLList::deleteNode(int e1)
{ if(head !=0)
    if(head==tail && e1==head->info)
    {
      delete head;
      head=tails=0;
    }

     else if(e1==head->info)
       {

       IntSLLMode *temp=head;
        head=head->next;
        delete temp;
       }
       else
        {
          IntSLLNode *pred, *temp;
          for(pred=head,temp =head->next;
              temp !=0 && !(tmp->info==e1);
               pred=pred->next,temp=temp->next);
           if(temp!=0)
           {
               pred->next=temp->next;
               if(temp==tail)
                tail=pred;
               delete temp;
           }
        }
}
bool IntSLList::isIntList(int e1) const
{
    InSLLNode *temp;
    for(temp=head;temp!=0 && !(temp->info==e1);temp=temp->next);
    return tmp !=0;
}
}
