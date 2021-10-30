#include <iostream>
using namespace std;

int gcd(int,int);

int main(){
   cout<<"Enter first number : ";
   int a;
   cin>>a;
   cout<<"Enter second number : ";
   int b;
   cin>>b;
   cout<<gcd(a,b)<<endl;
}

int gcd(int a,int b){
   int min = a<b?a:b;
   int greatestCommonDivisor = 1;
   for(int i=1;i<=min;i++){
      if(a%i==0 && b%i==0)
         greatestCommonDivisor=i;
   }
   return greatestCommonDivisor;
}

