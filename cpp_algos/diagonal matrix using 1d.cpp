#include <iostream>
using namespace std;

template <class T>
class diagonalmatrix{
public:
   diagonalmatrix(int size=10){
      n=size;
      arr = new T[n];
   }
   ~diagonalmatrix(){
      delete[] arr;
   }
   void set(){
      cout<<"Enter elements for diagonal top to bottom\n";
      for(int i=0;i<n;i++){
         cin>>arr[i];
      }cout<<endl;
   }
   void print(){
      cout<<"your diagonal matrix\n";
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            if(i==j){
               cout<<arr[i]<<"  ";
            }else{
               cout<<0<<"  ";
            }
         }cout<<endl;
      }cout<<endl;

   }

private:
   int n;
   T *arr;
};

int main(){
   int n=0;
   while(n<1){
      cout<<"Enter size of matrix : ";
      cin>>n;
      if(n<1)  cout<<"size can't be less than 1 !!!\n";
   }
   diagonalmatrix<int> ob(n);
   ob.set();
   ob.print();
}
