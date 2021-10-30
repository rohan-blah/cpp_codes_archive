#include <iostream>
using namespace std;

template <class T>
class upperTriangular{
public:
   upperTriangular(int size=10){
      n=size;
      eleC=n*(n+1)/2;
      arr=new T[eleC];
   }
   ~upperTriangular(){
      delete[] arr;
   }
   void set(){
      cout<<"Enter elements for lower triangular matrix\n left to right top to bottom(DON'T ENTER ELEMENTS OTHER THAN TRIANGLE!!)\n";
      for(int i=0;i<eleC;i++){
         cin>>arr[i];
      }cout<<endl;
   }
   T get(int i,int j){
      int pos=n*i-i*(i-1)/2+j-i;
      return arr[pos];
   }
private:
   int n;
   int eleC;
   T *arr;
};

int main(){
   upperTriangular<int> ob(5);
   ob.set();
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         cout<<((i<=j)?ob.get(i,j):0)<<"  ";
      }cout<<endl;
   }
}
