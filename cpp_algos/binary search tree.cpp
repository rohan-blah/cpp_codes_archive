#include<iostream>
using namespace std;
class node
{ public:
           node()
             {
                   left=right=NULL;
                   data=0;
                   visited=0;
                   }
             int data,visited;
             node *left,*right;
};
template<class t>
class stack
{
      public:
        t data;
        stack *prev;
};
template<class t>
class stacks
{
      stack<t> *top;
      public:
             stacks()
             {
                  top=NULL;
             }
void push(t n)
             {
                  stack<t> *temp;
                      temp=new stack<t>;
                      temp->data=n;
                      temp->prev=top;
                      top=temp;
             }

             t pop()
             {
                  t a;
                  if(top==NULL)
                  {
return NULL;
                  }
                  else
                  {
                      a=top->data;
                      top=top->prev;
                      return a;}}
 int empty()
             {
              if(top==NULL)
              return 0;
              else
              return 1;
             }
};
class tlist
{
      stacks<node*> st1,st2;
      int visited;
      public:
             node *root;
             tlist()
             {
                    root=NULL;

        visited=0;};
void create(int n,node *current)
{
                  if(root==NULL)
                  {
                                 cout<<"Entered in root making:\n";
                                 root=new node;
                                 root->data=n;
                                 root->left=root->right=NULL;
                  }
                  else
                  {
                      if((n<current->data)&&(current->left==NULL))
                      {
                                                                  node *temp;
                                                                  temp=new node;
                                                                  temp->data=n;
                                                                  temp->left=temp->right=NULL;
                                                                  current->left=temp;
                      }
                      else if((n>current->data)&&(current->right==NULL))
                      {
                                                                        node *temp;
                                                                        temp=new node;
                                                                        temp->data=n;
                                                                        temp->left=temp->right=NULL;
                                                                        current->right=temp;
                      }
                      else{
                                            if(n<current->data)
                                            create(n,current->left);
                                            else
                                            create(n,current->right);
                            }
                    }
}
 void post_order(const node *roote)
             {
                if(roote!=NULL)
                  {
                                post_order(roote->left);
                                post_order(roote->right);
                                cout<<roote->data<<endl;}}
 void pre_order(const node *roote)
             {
                  if(roote!=NULL)
                  {
                                cout<<roote->data<<endl;
                                pre_order(roote->left);
                                pre_order(roote->right);}}
 void in_order(const node *roote)
             {
                  if(roote!=NULL)
                  {in_order(roote->left);
                                cout<<roote->data<<endl;
                                in_order(roote->right);
                  }    }
void pre_order_nr()
             {
                  node *current=root;
                  while(current!=NULL)
                  {
                                      while((current!=NULL)&&(!visited))
                                      {
                                                     st1.push(current);
                                                     //if(current!=NULL)
                                                     cout<<current->data<<endl;
                                                     current=current->left;
                                      }
                                      current=st1.pop();
                                      if(current==NULL)
                                      break;
                                      visited=1;
                                      if(current->right!=NULL)
                                      {visited=0;
                                                              current=current->right;
                                      }}}
void post_order_nr()
             {
                node *tmp;
                  node *current=root;
                  while(current!=NULL)
                  { while((current!=NULL)&&(!current->visited))
                                      { st1.push(current);
                                       current=current->left;
                                      }
                  current=st1.pop();
                  if(current==NULL)
                  break;
      tmp=current->right;
               if((current->right!=NULL) &&(!tmp->visited))
                                      {
                                             st1.push(current);
                                                                current=current->right;
                                                              continue; }
if(!current->visited)
                                      {
                                                cout<<current->data<<endl;
                                                current->visited =1;
                                     }}}
void in_order_nr()
             {
               int ctr=0;
                  node *current=root;
                  while(current!=NULL)
                  {
                                      while((current!=NULL)&&(!visited))
                                      {
                                                     st1.push(current);
                                                     current=current->left;
                                      }
                                      current=st1.pop();
                                      if(current!=NULL)
                                      {
                                       cout<<current->data<<endl;
                                       ctr++;
                                      }
                                      else
                                      break;
                                      visited=1;
                                      if(current->right!=NULL)
                                      {
                                                              visited=0;
                                                              current=current->right;
                                      }}
cout<<"The number of nodes:\n"<<ctr<<endl;
             }
             void delete_node(int n)
             {
                  node *current=root;
                  node *succ,*prev,*tmp=NULL;
                  prev=NULL;
                  while((current!=NULL)&&(current->data!=n))
                  {
                                      if(current->data>n)
                                      {prev=current;
                                                         current=current->left;
                                      }
                                      else if(current->data<n)
                                      {
                                          prev=current;
                                          current=current->right;
                                      }
                  }
                  if(current==NULL)
                  cout<<"Data not found\n";
                  else
                  {
                    if(current->right!=NULL)
                    {succ=current->right;
                                          if(succ->left!=NULL)
                                          {
                                           while(succ->left!=NULL)
                                           {prev=succ;
                                                                  succ=succ->left;
                                           }
                                           prev->left=succ->right;
                                          }
                                          else
                                           current->right=succ->right;
                                           current->data=succ->data;}
 else{
if(prev->left!=NULL)
                         if(current->data==prev->left->data)
                          prev->left=current->left;
                         else
                          prev->right=current->left;
                        else
                         prev->right=current->left;}}}
 void delete_node_merge(int n)
             {
                  node *current=root;
                  node *succ,*prev,*tmp=NULL,*prev1=NULL;
                  prev=NULL;
                  while((current->data!=n)&&(current!=NULL))
                  {if(n<current->data)
                                      {prev=current;
                                                         current=current->left;
                                      }
                                      else
                                      {
                                          prev=current;
                                          current=current->right;}}
 if(current==NULL)
                  cout<<"Data not found\n";
                  else
                  {
if(current->right!=NULL)
                    {succ=current->right;
                                          if(succ->left!=NULL)
                                          {
                                           while(succ->left!=NULL)
                                           {
                                                                  prev1=succ;
                                                                  succ=succ->left;
                                           }
                                           prev1->left=succ->right;
                                           if(prev->left==current)
                                            prev->left=succ;
                                           else
                                            prev->right=succ;
                                           succ->left=current->left;
                                           succ->right=current->right;
                                           delete(current);}
            else
                                          {
                                           if(prev->left==current)
                                           {
                                            prev->left=succ;
                                            succ->left=current->left;
                                            delete(current);
                                           }
                                           else if(prev->right==current)
                                           {
                                            prev->right=succ;
                                            succ->left=current->left;
                                            delete(current);}}
 }else{
if(prev->left!=NULL)
                         if(current->data==prev->left->data)
                          {
                           tmp=current;
                           prev->left=current->left;
                          }
                         else if(current->data==prev->right->data)
                          {
                           tmp=current;
                           prev->right=current->left;
                          }
                         else
                          {
                           tmp=current;
                           prev->right=current->left;}
 else{tmp=current;
                         prev->right=current->left;
                        }
                        delete(tmp); }}
             }
void display_leaf()
             {
              visited=0;
              node *current=root;
              while(current!=NULL)
                  {while((current!=NULL)&&(!visited))
                                      {st1.push(current);
                                                     current=current->left; }
                                      current=st1.pop();
                                      if(current!=NULL)
                                       {
                                        if((current->left==NULL)&&(current->right==NULL))
                                        cout<<current->data<<endl; }
                                     else
                                     break;
                                      visited=1;
                                      if(current->right!=NULL)
                                      {visited=0;
                                                              current=current->right; }}}
             int display_level()
             {int c=0;
              node *current=root;
              st1.push(current);
              while((st1.empty())||(st2.empty()))
              {if(st1.empty()!=0)
               {while(st1.empty())
                {current=st1.pop();
                 cout<<current->data<<" -> ";
                 if(current->right!=NULL)
                  st2.push(current->right);
                 if(current->left!=NULL)
                  st2.push(current->left);
                }
                c++;
               }
               else
                break;
               cout<<endl;
               if(st2.empty()!=0)
               {
                while(st2.empty())
                {
                 current=st2.pop();
                 cout<<current->data<<" -> ";
                 if(current->right!=NULL)
                  st1.push(current->right);
                 if(current->left!=NULL)
                  st1.push(current->left);
                }
                c++;
               }
               else
                break;
               cout<<endl;
              }
              return c;}
             void mirror_r()
             {node *tmp,*temp=NULL;
                  node *current=root;
                  while(current!=NULL)
                  { while((current!=NULL)&&(!current->visited))
                                      { st1.push(current);
                                       current=current->left;
                                      }
                  current=st1.pop();
                  if(current==NULL)
                  break;
      tmp=current->right;
if((current->right!=NULL) &&(!tmp->visited))
                                      { st1.push(current);
                                                                current=current->right;
                                                              continue; }
if(!current->visited)
                                      {
                                                if(current!=NULL)
                                      {
                                     temp=current->right;
                                       current->right=current->left;
                                       current->left=temp; }
current->visited =1; }}    }   };
int main()
{char ch;
    int n=1;
    tlist t1;
    cout<<"Enter the numbers(enter 0 to terminate:)\n";
    for(int i=0;n!=0;i++)
    {cout<<"\nEnter the value:\n";
            cin>>n;
            cout<<endl;
            if(n!=0)
            t1.create(n,t1.root); }
    cout<<"Answer with post_order recursion:\n";
    cout<<"The post_order without recursion:\n";
    t1.in_order_nr();
    do{cout<<"Wanna delete any data:\n";
               cin>>ch;
               if(ch=='y')
               {cout<<"Enter the number u want to delete:\n";
                          cin>>n;
                          t1.delete_node_merge(n); }
    }while(ch=='y');
    cout<<"The resulting numbers in tree:\n";
    t1.in_order(t1.root);
    cout<<"Want to see leaf nodes:\n";
    cin>>ch;
    if(ch=='y')
    t1.display_leaf();
    cout<<"The current tree:\n";
    t1.pre_order(t1.root);
    cout<<"want to see mirror image:\n";
    cin>>ch;
    if(ch=='y')
     t1.mirror_r();
     cout<<"The current tree:\n";
    t1.in_order(t1.root);
    int height;
    cout<<"Want to see level wise tree:\n";
    cin>>ch;
 if(ch=='y')
 {height=t1.display_level();
  cout<<"The height of tree is:\t"<<height<<endl;
  }
 return 0; }

