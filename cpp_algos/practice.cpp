#include<iostream>
using namespace std;
int main()
{
 int n,r,gen[50],message[50];
 cout<<"At Sender's End "<<endl;
 cout<<"Enter the number of message bits : ";
 cin>>n;

 cout<<"Enter the number of generator bits : ";
 cin>>r;
 cout<<"Enter the message : ";
 for(int i=0;i<n;i++)
     cin>>message[i];
 cout<<"Enter the generator : ";
 for(int i=0;i<r;i++)
     cin>>gen[i];
 r--;
 for(int i=0;i<r;i++)
     cout<<message[n+i] ;
     return 0;
}
