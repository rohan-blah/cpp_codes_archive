#include<iostream>


using namespace std;

template <class T>
void Lsearch(T *a, T item, int n)
{
 int z=0;
 for(int i=0;i<n;i++)
 {
  if(a[i]== item)
  {
   z=1;
   cout<<"\n Item found at position = "<<i+1<<"\n\n";
  }
  else
   if(z!=1)
  {
   z=0;
  }
 }

 if(z==0)
  cout<<"\n Item not found in the list\n\n";
}

template <class T>
void Bsearch(T *a, T item, int n)
{
 int beg=0,end=n-1;
 int mid=beg+end/2;

 while((a[mid]!=item) && (n>0))
 {
  if(item>a[mid])
   beg=mid;
  else
   end=mid;

  mid=(beg+end)/2;

  n--;
 }

 if(a[mid]==item)
  cout<<"\n Item found at position = "<<mid+1<<"\n\n";
 else
  cout<<"\n Item not found in the list\n\n";

}



int main()
{
 int iarr[20] ;
 int iele,n;
 char ch;
 cout<<"Enter the size of array:";
 cin>>n;

 cout<<"\n Enter Elements of Integer Array \n";
 for(int i=0;i<n;i++)
 {

     cin>>iarr[i];
 }
 cout<<"\nThe Elements are:\n";
 for(int i=0;i<n;i++)
 {
  cout<<" "<<iarr[i]<<" ,";
 }

  cout<<"\n\n Enter an item to be search: ";
 cin>>iele;
 cout<<"\n\n Linear Search Method\n";
 Lsearch(iarr,iele,n);



 cout<<"\n\n Binary Search method\n";
 Bsearch(iarr,iele,n);



return 0;
}
