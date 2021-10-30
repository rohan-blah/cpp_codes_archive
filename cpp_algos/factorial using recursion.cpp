#include <iostream>
using namespace std;

int factorial(int);
void factor(int,int);

int main(){
   cout<<"Enter number for factorial : ";
   int n;
   cin>>n;
   cout<<"Factorial for "<<n<<" : "<<factorial(n)<<endl;
   cout<<"Factors of "<<n<<" : ";
   factor(n,1);
}

int factorial(int n){
   if(n==0) return 1;

   return n*factorial(n-1);
}

void factor(int n,int i=2){
   int num=n;
   do{
      if(num%i==0){
         if(i!=1) cout<<" * ";
         cout<<i;
         num=num/i;
         factor(num,2);
         return;
      }
      else{
         i++;
      }
   }while(num!=1);
   cout<<endl;
}
