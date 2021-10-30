#include<iostream>
using namespace std;
const int s=5;
int flag=0;
template<class t>
class CircularQueues
{
      t queue[s];
      int f,r;
      public:
             CircularQueues()
             {
                 f=r=-1;
             }

             void insert(t n)
             {
                  if((r+1)%s!=f)
                  {
                                          r=(r+1)%s;
                                          queue[r]=n;
                                          if(f<0)
                                          f=0;
                  }
                   else
                  {
                     cout<<"Queue overflow element not inserted:\n";
                     flag=-1;

                  }
             }

             t remove()
             {
                 t a;
                 if(empty()!=-1)
                 {
                              if((f==r)&&(f>=0))
                              {
                                             a=queue[f];
                                             f=r=-1;
                              }
                              else if(f!=s-1)
                              {
                                               a=queue[f++];
                              }
                              else
                              {
                                               f=0;
                                               a=queue[f];
                              }
                              return a;
                 }
                 else
                 {
                     cout<<"Queue underflow:\n";
                     return -1;
                 }
             }

             int empty()
             {
                 if(f==-1)
                 return -1;
                 else
                 return 0;
             }

             void display()
             {
                  if(empty()==-1)
                  {
                                                  cout<<"Empty queue:\n";
                  }
                  else
                  {
                      int rear,front;
                      rear=r;
                      front=f;
                      while((front+1)%s!=(rear+1)%s)
                      {
                                          cout<<queue[front]<<endl;
                                          front=(front+1)%s;
                      }
                      cout<<queue[front]<<endl;


                  }
             }

};
int main()
{
CircularQueues <char> q1;
    char ch;
    char n;
    flag=0;
    do
    {
         cout<<"Enter 'y' if want to enter any element:\n";
         cin>>ch;
         if(ch=='y')
         {
                    cout<<"Enter the element:\n";
                    cin>>n;
                    q1.insert(n);
                    if(flag==-1)
                    break;
         }

    }while(ch=='y');

    cout<<"The resulting queue:\n";
    q1.display();

    flag=0;
    if(q1.empty()!=-1)
    {
    do
    {
         cout<<"Enter 'y' if want to remove any element:\n";
         cin>>ch;
         if(ch=='y')
         {
                    n=q1.remove();
                    if(n==-1)
                    break;
         }
    }while(ch=='y');

    cout<<"The resulting queue:\n";
    q1.display();

    do
    {
         cout<<"Enter 'y' if want to enter any element:\n";
         cin>>ch;
         if(ch=='y')
         {
                    cout<<"Enter the element:\n";
                    cin>>n;
                    q1.insert(n);
                    if(flag==-1)
                    break;
         }
    }while(ch=='y');

    cout<<"The resulting queue:\n";
    q1.display();
    }

    return 0;
}
