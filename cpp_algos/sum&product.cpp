#include<iostream>
using namespace std;
int main()
{
 int n,i,sum=0,g=1;
 cout<<"Enter the no:";
 cin>>n;
 for(i=1;i<=n;i++)
 {if(g==-1)
   {

     sum-=i;
   }
 else
    sum+=i;
 g=g*-1;
}
cout<<sum;
return 0;
}
