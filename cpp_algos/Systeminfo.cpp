#include<iostream>
using namespace std;

int main()
{
    char ch;
    int a;
    do{

  cout<<" Enter the type of information you want to get:\n 1. Kernel Version\n 2. CPU type and model\n 3. Information on configured memory, amount of free and used memory\n   ";
  cin>>a;



     if(a==1)
     {
       cout<<" \n The Kernel version is 18363.1016 ";
     }
     else if(a==2)
     {
       cout<<"\n CPU Type and Model is:  1 Processor(s) Installed.\n\t\t[01]: AMD64 Family 23 Model 17 Stepping 0 AuthenticAMD ~2000 Mhz";
     }
     else if(a==3)
     {
       cout<<"\n Information on configured memory, amount of free and used memory is:\n Total Physical Memory: 7,116 MB\n Available Physical Memory: 2,280 MB\n Virtual Memory: Max Size: 12,685 MB\n Virtual Memory: Available: 3,770 MB\n Virtual Memory: In Use: 8,915 MB";
     }
  cout<<" \nDo you want to continue: ";
  cin>>ch;
}while(ch=='y');

return 0 ;
}
