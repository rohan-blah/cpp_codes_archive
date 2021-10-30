#include<iostream>
using namespace std;

int partition(int ar[],int l,int r){
	int pivot=ar[r];
	int pi=l;
	for(int i=l;i<r;i++){
		if(ar[i]<=pivot){
			int temp=ar[i];
			ar[i]=ar[pi];
			ar[pi]=temp;
			pi++;
		}
	}
	int temp=ar[pi];
	ar[pi]=ar[r];
	ar[r]=temp;
	return pi;
}

void quicksort(int ar[],int l,int r){
	if(l<r){
		int pi=partition(ar,l,r);
		quicksort(ar,l,pi-1);
		quicksort(ar,pi+1,r);
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
		cout<<i<<" ";
	quicksort(ar,0,n-1);
	cout<<endl<<"Elements after sorting"<<endl;
	for(int i:ar)
		cout<<i<<" ";
	return 0;
}
