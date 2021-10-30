#include <iostream>
using namespace std;

int factorial(int);
void factor(int);

int main(){
   cout<<"Enter number for factorial : ";
   int n;
   cin>>n;
   cout<<"factorial "<<n<<" : "<<factorial(n);
   cout<<"\nFactors of "<<n<<" : ";
   factor(n);
}

int factorial(int n){
   int fact=1;
   for (int i=1;i<=n;i++){
      fact*=i;
   }
   return fact;
}

void factor(int n){
   int num=n;
   for(int i=1;i<=num;i++){
      if(num%i==0){
	if(i!=1)   cout<<" * ";
         cout<<i;
         num=num/i;
         i=1;
      }
   }
}
