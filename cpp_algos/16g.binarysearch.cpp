#include<iostream>
using namespace std;
int binarysearch(int ar[],int n,int key){
	int l=0,r=n-1;
	
	while(l<=r){
		int mid=(r+l+1)/2;
		if(ar[mid]==key)
			return mid;
		if(ar[mid]<key)
			l=mid+1;
		if(ar[mid]>key)
			r=mid-1;
	}
	return -1;
}
int main(){
	int n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
    int ar[n];
	cout<<"Enter array elements in ascending order"<<endl;
	for(int i=0;i<n;i++){
	  cin>>ar[i];
	}
	cout<<"Enter a key to search for"<<endl;
	int key;
	cin>>key;
	cout<<"Element found at index "<<binarysearch(ar,n,key)<<endl;
	return 0;
}
