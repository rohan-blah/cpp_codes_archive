#include <iostream>
using namespace std;

template <class T>
class lowerTriangular{
public:
   lowerTriangular(int size=10){
      n=size;
      eleC=n*(n+1)/2;
      arr=new T[eleC];
   }
   ~lowerTriangular(){
      delete[] arr;
   }
   void set(){
      cout<<"Enter elements for lower triangular matrix\n to store in row major\n";
      for(int i=0;i<eleC;i++){
         cin>>arr[i];
      }cout<<endl;
   }
   T get(int i,int j){
      int pos=i*(i+1)/2+j;
      return arr[pos];
   }
private:
   int n;
   int eleC;
   T *arr;
};

int main(){
   lowerTriangular<int> ob(5);
   ob.set();
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         cout<<((i>=j)?ob.get(i,j):0)<<"  ";
      }cout<<endl;
   }
}
