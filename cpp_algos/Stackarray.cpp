#include<iostream>
using namespace std;
int top=-1,n=20;

bool isfull()
{
    if(top==n-1)
    return true;
    else
    return false;
}
bool isempty()
{
    if(top==-1)
    return true;
    else
    return false;
}
void push(int arr[],int &top,int item)
{
    if(isfull()==true)
    cout<<"Overflow";
    else
    {
    arr[++top]=item;
    cout<<"Element pushed!!";
    }
}
void pop(int arr[],int &top)
{
    if(isempty()==true)
    cout<<"Underflow";
    else
    {
    cout<<"Element popped : "<<arr[top];
    top--;
    }

}
void print(int arr[],int top)
{
    cout<<"Stack is : ";
    for(int i=0;i<=top;i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int arr[n],c,t;
    char f='y';
    while(f=='y')
    {
        cout<<"1.push\n2.pop\n3.print";
        cout<<"\nEnter your choice : ";
        cin>>c;
        switch(c)
        {
        case 1:
            cout<<"Enter item: ";
            cin>>t;
            push(arr,top,t);
            break;
        case 2:
            pop(arr,top);
            break;
        case 3:
            print(arr,top);
            break;
        default:
            cout<<"\nError!Invalid choice\n";
        }
        cout<<"\nWant to continue?(y/n):";
        cin>>f;
        cout<<endl;
    }
    return 0;
}
