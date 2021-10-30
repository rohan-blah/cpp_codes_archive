#include <iostream>
using namespace std;

int* fibbonacci(int);
const int MAX = 100;
int main(){
   int* arr;
   cout<<"Enter length of fibbonacci series : ";
   int n;
   cin>>n;
   arr=fibbonacci(n);
   for(int i=0;i<n;i++)
      cout<<*(arr+i)<<"  ";
   cout<<endl;
}

int* fibbonacci(int n){
   static int series[MAX];
   if(n==1){
      series[0]=0;
   }
   else{
      series[0]=0;
      series[1]=1;
      if(n>2){
         int n1=0,n2=1;
         int n3;
         for(int i=2;i<n;i++){
            n3=n1+n2;
            series[i]=n3;
            n1=n2;
            n2=n3;
         }
      }
   }
   return series;
}
