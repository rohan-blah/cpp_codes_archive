#include <iostream>
using namespace std;

template <class T>
class symmetric{
public:
   symmetric(int size=10){
      n=size;
      eleD=n*(n+1)/2;
      arr=new T[eleD];
   }
   ~symmetric(){
      delete[] arr;
   }
   void set(){
      cout<<"Enter elements to store in row major\n(Don't give the elements under diagonal)\n";
      for(int i=0;i<eleD;i++){
         cin>>arr[i];
      }
      for(int i=0;i<eleD;i++){
         cout<<arr[i];
      }cout<<endl;
   }
/*
  i/j| 1 2 3 4
 ----|---------
   1 | 0 1 2 3
   2 | 1 4 5 6
   3 | 2 5 7 8
   4 | 3 6 8 9

  [0,1,2,3,4,5,6,7,8,9]
 k|0 1 2 3 4 5 6 7 8 9
*/

   T get(int i,int j){
      int pos=n*i-i*(i-1)/2+j-i;
      return arr[pos];

   }
private:
   int n;
   int eleD;
   T *arr;
};

int main(){
   cout<<"Enter size of matrix : ";
   int s;
   cin>>s;
   symmetric<int> ob(s);
   ob.set();
   for(int i=0;i<s;i++){
      for(int j=0;j<s;j++){
         if(i<=j)
            cout<<ob.get(i,j)<<"  ";
         else
            cout<<ob.get(j,i)<<"  ";
      }cout<<endl;
   }
}
