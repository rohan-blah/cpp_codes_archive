#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main()
{
    int i,n,a[100],k=0,flag=0;
    char ch;
again:
    {

    cout<<"\nEnter the amount of Number you want to add:";
    cin>>n;
    cout<<"\nEnter the No you want to add:";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        k+=a[i];
    }
   cout<<"\nYour SUM is:"<<k<<endl;

cout<<"\nDo you want to continue Y/N:";
cin>>ch;

   if(ch=='y'||'Y')
   {   k=0;
       goto again;
       flag=1;
   }


    }

return 0;


}
