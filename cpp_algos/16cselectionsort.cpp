#include<iostream>
using namespace std;

void selectionsort(int ar[],int n){
	for(int i=0;i<n-1;i++){
		int min_ind=i;
		for(int j=i+1;j<n;j++)
			if(ar[j]<ar[min_ind]){
				min_ind=j;
			}
		int temp=ar[i];
		ar[i]=ar[min_ind];
		ar[min_ind]=temp;
	}
}

int main(){
	cout<<"Enter the size of array"<<endl;
	int n;
	cin>>n;
	int ar[n];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	cout<<"Elements before sorting"<<endl;
	for(int i:ar)
		cout<<i<<endl;
	selectionsort(ar,n);
	cout<<"Elements after sorting"<<endl;
	for(int i:ar)
		cout<<i<<" ";
	return 0;
}
