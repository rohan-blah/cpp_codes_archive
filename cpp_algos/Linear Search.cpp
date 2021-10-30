/*Program for Linear Search*/
#include<iostream>

using namespace std;

int main()
{
   int n,a[50],i,x;                                      //Initialisation of variables

    cout<<"Enter the no. of elements in array :";         //The size of array is declaring
    cin>>n;                                              //Initialisation of size of array
    cout<<"\nEnter the no. of elements in array :";        //Entering elements in array
    for(i=0;i<n;i++)
    {
      cin>>a[i];
      cout<<" ";
    }
    cout<<" \n\nThe entered elements in array is :";        //Showing elements in array
    for(i=0;i<n;i++)
    {
      cout<<a[i];
      cout<<" ";
    }
    cout<<"\n\nEnter the element to be found:";             //Asking user to enter the element to be searched
    cin>>x;                                             //Initialisation of element to be found
    for(i=0;i<n;i++)
    {
      if(a[i]==x)      //comparing the element to be found in the array list if found then show the position
       {
        cout<<"\nYour element  "<<x<<"  found at: "<<i<<" Index Value";
        break;
       }

      if(!a[i]==x)
      {            //If not found then show not in list and exit
        cout<<"\nThe element was not found in array!!";
      }
    }

return 0;
}
