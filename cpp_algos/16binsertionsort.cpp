#include<iostream>
using namespace std;

void insertionsort(int ar[],int n){
	for(int i=1;i<n;i++){
		int key=ar[i];
		int j=i-1;
		while(j>=0&&ar[j]>key){
			ar[j+1]=ar[j];
			j=j-1;
		}
		ar[j+1]=key;
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
	insertionsort(ar,n);
	cout<<"Elements after sorting"<<endl;
	for(int i:ar)
		cout<<i<<" ";
	return 0;
}
