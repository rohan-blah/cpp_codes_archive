#include <iostream>
using namespace std;

int gcd(int,int,int);

int main(){
   cout<<"Enter first number : ";
   int a;
   cin>>a;
   cout<<"Enter second number : ";
   int b;
   cin>>b;
   cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a,b,a<b?a:b)<<endl;
}

int gcd(int a,int b,int min){
   if(a%min==0 && b%min==0)
      return min;
   else
      return gcd(a,b,min-1);
}
