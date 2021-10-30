#include <iostream>
#include <stdlib.h>
using namespace std;

int bubble(short int a[],int n)
{
    int c=0;
    int temp ;
    for(int i=1;i<n;i++)
    {
        int t=0;
        for(int j=0;j<n-i; j++)
        {
            if(a[j+1]<a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                c++;
                t=1;
            }
        }
        if(t==0)
        break;
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<"  ";
        }
    }
    return c;
}

int main()
{
    short int arr[20],n , i , arr1 ;
    cout<<"\nEnter the no of elements in array: ";
    cin>>n;
    cout<<"\nthe array is :";
    for( i=0;i<n;i++)
    {
        arr[i]=rand()%10;
        cout<<arr[i]<<" ";
    }
    cout<<"\nThe list is: \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    arr1=bubble(arr,n);

    cout<<"\nThe list after sorting is: \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<"\nThe total no. of comparisons after sorting : "<<arr1;
    return 0;
}
