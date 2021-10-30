#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
using namespace std;
int main()
{
   string s;
   string temp;
   int num,i=-1,arr[10];
   stringstream ss;
   getline(cin,s);
   ss<<s;
   while(!ss.eof())
   {
       ss>>temp;
       if(stringstream(temp)>>num)
        {
           arr[++i]=num;
        }
        else
        {
            if(temp=="+")
            arr[i-1]=arr[i-1]+arr[i];
            else if(temp=="-")
            arr[i-1]=arr[i-1]-arr[i];
            else if(temp=="*")
            arr[i-1]=arr[i-1]*arr[i];
            else if(temp=="/")
            arr[i-1]=arr[i-1]/arr[i];

        --i;
        }
   }
   cout<<"Answer:"<<arr[0];
   return 0;
}
