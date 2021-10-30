//INSERTION SORT PROGRAM
#include<iostream>
using namespace std;
int main()
{
 int a[10]={12,4,3,1,15,45,33,21,10,2};
 cout<<"\nEntered array is:\n";
 for(int i=0;i<10;i++)  //value is being entered through loop
 {
     cout<<a[i]<<"\t";
 }
 for(int k=1;k<10;k++) //this loop will sort the array
 {
     int temp=a[k];  //value of a[k] at 1 is been transfered in temp
     int  j=k-1; //value at k-1 i.e. at array index 0 is been transfered in j
     while(j>=0&&temp<=a[j])//comparing for swapping the value
     {
         a[j+1]=a[j];        //Swapping the value and sorting the array
         j=j-1;
     }
     a[j+1]=temp;    //value of temp is been now assigned to a[j+1]
 }
  cout<<"\nSorted list is\n";
  for(int i=0;i<10;i++)
  {
      cout<<a[i]<<"\t";
  }
  return 0;
}
