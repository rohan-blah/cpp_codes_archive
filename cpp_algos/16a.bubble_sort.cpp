#include<iostream>
using namespace std;

void bubble_sort(int ar[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    cout<<"Array before sorting: "<<endl;
    for(int i:ar)
        cout<<i<<" ";
        cout<<endl<<"Array after sorting in ascending order: "<<endl;
    bubble_sort(ar,7);
    for(int i:ar)
        cout<<i<<" ";
    return 0;
}